from cv2 import exp


class LambdaTerm:
    """λ表达式的基类"""
    def __eq__(self, other):
        return isinstance(other, type(self)) and self.__dict__ == other.__dict__

    def __repr__(self):
        return str(self)


class Variable(LambdaTerm):
    """表示变量"""
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return self.name

    def free_variables(self):
        """返回自由变量集合"""
        return {self.name}

    def substitute(self, var, term):
        """替换变量"""
        if self.name == var.name:
            return term
        return self


class Abstraction(LambdaTerm):
    """表示λ抽象 (λx.M)"""
    def __init__(self, param, body):
        self.param = param  # 变量
        self.body = body    # λ项

    def __str__(self):
        return f"λ{self.param}.{self.body}"

    def free_variables(self):
        """返回自由变量集合"""
        return self.body.free_variables() - {self.param.name}

    def substitute(self, var, term):
        """替换变量，必要时进行α-转换避免变量捕获"""
        if self.param.name == var.name:
            return self

        # 检查是否需要α-转换
        if self.param.name in term.free_variables():
            # 生成新的变量名
            new_name = self._generate_new_name(term)
            new_param = Variable(new_name)
            # 对body进行α-转换
            new_body = self.body.substitute(self.param, new_param)
            # 然后进行替换
            return Abstraction(new_param, new_body.substitute(var, term))

        return Abstraction(self.param, self.body.substitute(var, term))

    def _generate_new_name(self, term):
        """生成不与term中自由变量冲突的新变量名"""
        used_names = term.free_variables() | {self.param.name}
        i = 0
        while True:
            new_name = f"x{i}"
            if new_name not in used_names:
                return new_name
            i += 1


class Application(LambdaTerm):
    """表示应用 (M N)"""
    def __init__(self, func, arg):
        self.func = func  # 函数
        self.arg = arg    # 参数

    def __str__(self):
        func_str = f"({self.func})" if isinstance(self.func, (Abstraction, Application)) else str(self.func)
        arg_str = f"({self.arg})" if isinstance(self.arg, (Abstraction, Application)) else str(self.arg)
        return f"{func_str} {arg_str}"

    def free_variables(self):
        """返回自由变量集合"""
        return self.func.free_variables() | self.arg.free_variables()

    def substitute(self, var, term):
        """替换变量"""
        return Application(
            self.func.substitute(var, term),
            self.arg.substitute(var, term)
        )


def parse_lambda(s):
    """解析字符串形式的λ表达式"""
    s = s.replace(" ", "").replace("λ", "\u03bb")  # 统一使用λ符号
    index = 0
    n = len(s)

    def parse_variable():
        nonlocal index
        start = index
        while index < n and s[index].isalpha():
            index += 1
        return Variable(s[start:index])

    def parse_abstraction():
        nonlocal index
        index += 1  # 跳过λ
        param = parse_variable()
        if index < n and s[index] == '.':
            index += 1  # 跳过.
        body = parse_expression()
        return Abstraction(param, body)

    def parse_application():
        terms = [parse_atom()]
        while index < n and s[index] not in ')':
            terms.append(parse_atom())

        # 构建应用链
        result = terms[0]
        for term in terms[1:]:
            result = Application(result, term)
        return result

    def parse_atom():
        nonlocal index
        if index >= n:
            raise SyntaxError("Unexpected end of input")

        if s[index] == '(':
            index += 1  # 跳过(
            expr = parse_expression()
            if index < n and s[index] == ')':
                index += 1  # 跳过)
            else:
                raise SyntaxError("Unclosed parenthesis")
            return expr
        elif s[index] == '\u03bb':  # λ符号
            return parse_abstraction()
        elif s[index].isalpha():
            return parse_variable()
        else:
            raise SyntaxError(f"Unexpected character: {s[index]}")

    def parse_expression():
        return parse_application()

    return parse_expression()


def beta_reduce(term):
    """执行一次β-归约（最左最外策略）"""
    if isinstance(term, Application):
        # 检查是否是一个redex (λx.M) N
        if isinstance(term.func, Abstraction):
            # 执行β-归约：(λx.M) N → M[x := N]
            return term.func.body.substitute(term.func.param, term.arg)

        # 先尝试归约函数部分
        reduced_func = beta_reduce(term.func)
        if reduced_func != term.func:
            return Application(reduced_func, term.arg)

        # 再尝试归约参数部分
        reduced_arg = beta_reduce(term.arg)
        if reduced_arg != term.arg:
            return Application(term.func, reduced_arg)

    elif isinstance(term, Abstraction):
        # 归约抽象的主体
        reduced_body = beta_reduce(term.body)
        if reduced_body != term.body:
            return Abstraction(term.param, reduced_body)

    # 如果不能归约，返回原项
    return term


def normalize(term, max_steps=1000):
    """计算λ表达式的β-范式，使用最左最外归约策略"""
    steps = 0
    while True:
        reduced = beta_reduce(term)
        if reduced == term or steps >= max_steps:
            return term
        term = reduced
        steps += 1


# 示例用法
if __name__ == "__main__":
    # 示例1: (λx.x) y → y
    expr1 = parse_lambda("(λx.x) y")
    print(f"原始表达式: {expr1}")
    print(f"β-范式: {normalize(expr1)}\n")

    # 示例2: λx.(λg.λy.gy)((λg.λy.gy)((λg.λy.gy)((λg.λy.gy)x)))
    expr2 = parse_lambda("λx.(λg.λy.gy)((λg.λy.gy)((λg.λy.gy)((λg.λy.gy)x)))")
    print(f"原始表达式: {expr2}")
    print(f"β-范式: {normalize(expr2)}\n")

    # 示例3: (λx.λy.x) a b → a
    expr3 = parse_lambda("(λx.λy.x) a b")
    print(f"原始表达式: {expr3}")
    print(f"β-范式: {normalize(expr3)}")

    expr4 = parse_lambda("λx.λy.x y")
    print(f"原始表达式: {expr4}")
    print(f"β-范式: {normalize(expr4)}")

    expr5 = parse_lambda("(λx.(λg.λy.gy)((λg.λy.gy)((λg.λy.gy)((λg.λy.gy)x))))")
    print(f"原始表达式: {expr5}")
    print(f"β-范式: {normalize(expr5)}")
