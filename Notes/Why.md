
#

#### 为什么是 A 而不是 B

在 `C++11` 中，函数声明有两种语法

`return-type identifier ( argument-declarations... )`


`auto identifier ( argument-declarations... ) -> return_type`

为什么它们等效而使用后者, 因为 `C++11` 引入了 `decltype` 允许你描述表达式的类型

考虑到

```cpp
template <typename T1, typename T2>
decltype(a + b) compose(T1 a, T2 b);
```

编译器会告诉你它不知道 `decltype` 参数中的 `a` 和 `b` 是什么。那是因为它们仅由参数列表声明。

可以通过使用 `declval` 和已声明的模板参数解决

```cpp
template <typename T1, typename T2>
decltype(std::declval<T1>() + std::declval<T2>())
compose(T1 a, T2 b);
```

但是相对冗长，所以

```cpp
template <typename T1, typename T2>
auto compose(T1 a, T2 b) -> decltype(a + b);
```

另外，`C++14` 允许 

`auto identifier ( argument-declarations... )`

只要函数在使用前已完全定义，并且所有 `return` 语句都推导出相同的类型。

此外，`->` 是在 lambda 中显式指定返回类型的唯一方法.

同时在类里面允许直接使用类中定义的返回类型定义类成员函数，而无需再次提供 `class::` 范围解析前缀。

```cpp
SomeVeryLongClassName::SomeVeryLongReturnTypeName SomeVeryLongFunctionName() { ... } 
```

替换为

```cpp
auto SomeVeryLongFunctionName() -> SomeVeryLongReturnTypeName { ... } 
```

但是，考虑 `UEC++`

不应在 `C++` 代码中使用 `auto`，下面列出的少数例外情况除外。

始终明确您要初始化的类型。这意味着该类型必须对读者清晰可见。此规则也适用于 `C#` 中 `var` 关键字的使用。

也不应使用 `C++17` 的结构化绑定功能，因为它实际上是可变参数 `auto`.

可接受的 auto 用法：

- 当需要将 lambda 绑定到变量时，因为 lambda 类型在代码中不可表示。

- 对于迭代器变量，但仅限于迭代器的类型很详细且会影响可读性的情况。

- 在模板代码中，表达式的类型不容易辨别。这是一个高级案例。

如果以可接受的方式使用 `auto`，请始终记住正确使用 `const`、`&` 或 `*`，就像使用类型名称一样。

使用 `auto`，这将强制推断的类型为所需的类型。

为什么 `UEC++` 有这样的限制，暂时不知道




