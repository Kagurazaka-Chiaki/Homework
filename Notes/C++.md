# C/C++

#### `const`

##### 作用

- 修饰变量，说明该变量不可以被改变；
- 修饰指针，分为指向常量的指针（`pointer to const`）和自身是常量的指针（常量指针，`const pointer`）；
- 修饰引用，指向常量的引用（`reference to const`），用于形参类型，即避免了拷贝，又避免了函数对值的修改；
- 修饰成员函数，说明该成员函数内不能修改成员变量。

##### 宏定义 `#define` 和 `const` 常量

| 宏定义 `#define`       | `const` 常量   |
| ---------------------- | -------------- |
| 宏定义，相当于字符替换 | 常量声明       |
| 预处理器处理           | 编译器处理     |
| 无类型安全检查         | 有类型安全检查 |
| 不分配内存             | 要分配内存     |
| 存储在代码段           | 存储在数据段   |
| 可通过 `#undef` 取消   | 不可取消       |

#### `static`

##### 作用

- 修饰普通变量，修改变量的存储区域和生命周期，使变量存储在静态区，
  在 `main` 函数运行前就分配了空间，如果有初始值就用初始值初始化它，如果没有初始值系统用默认值初始化它。
- 修饰普通函数，表明函数的作用范围，仅在定义该函数的文件内才能使用。
  在多人开发项目时，为了防止与他人命名空间里的函数重名，可以将函数定位为 `static`。
- 修饰成员变量，修饰成员变量使所有的对象只保存一个该变量，而且不需要生成对象就可以访问该成员。
- 修饰成员函数，修饰成员函数使得不需要生成对象就可以访问该函数，但是在 `static` 函数内不能访问非静态成员。

#### `this` 指针

- `this` 指针是一个隐含于每一个非静态成员函数中的特殊指针。它指向调用该成员函数的那个对象。
- 当对一个对象调用成员函数时，编译程序先将对象的地址赋给 `this` 指针，然后调用成员函数，
  每次成员函数存取数据成员时，都隐式使用 `this` 指针。
- 当一个成员函数被调用时，自动向它传递一个隐含的参数，该参数是一个指向这个成员函数所在的对象的指针。
- `this` 指针被隐含地声明为: `ClassName *const this`，这意味着不能给 `this` 指针赋值；
  在 `ClassName` 类的 `const` 成员函数中，`this` 指针的类型为：`const ClassName* const`，
  这说明不能对 `this` 指针所指向的这种对象是不可修改的（即不能对这种对象的数据成员进行赋值操作）；
- `this` 并不是一个常规变量，而是个右值，所以不能取得 `this` 的地址（不能 `&this`）。
- 在以下场景中，经常需要显式引用 `this` 指针：
  - 为实现对象的链式引用；
  - 为避免对同一对象进行赋值操作；
  - 在实现一些数据结构时，如 `linked_list`。

#### `inline` 内联

##### 特征

相当于把内联函数里面的内容写在调用内联函数处；
相当于不用执行进入函数的步骤，直接执行函数体；
相当于宏，却比宏多了类型检查，真正具有函数特性；
编译器一般不内联包含循环、递归、switch 等复杂操作的内联函数；
在类声明中定义的函数，除了虚函数的其他函数都会自动隐式地当成内联函数。

##### 使用

`inline` 使用

```cpp
// 声明 1（加 inline，建议使用）
inline int functionName(int first, int second,...);

// 声明 2（不加 inline）
int functionName(int first, int second,...);

// 定义
inline int functionName(int first, int second,...) {};

// 类内定义，隐式内联
class A {
    int doA() { return 0; } // 隐式内联
}

// 类外定义，需要显式内联
class A {
    int doA();
}
inline int A::doA() { return 0; } // 需要显式内联
```

##### 编译器对 `inline` 函数的处理步骤

- 将 `inline` 函数体复制到 `inline` 函数调用点处；
- 为所用 `inline` 函数中的局部变量分配内存空间；
- 将 `inline` 函数的的输入参数和返回值映射到调用方法的局部变量空间中；
- 如果 `inline` 函数有多个返回点，将其转变为 `inline` 函数代码块末尾的分支（使用 `goto`）。

##### 优缺点

- 优点

  1. 内联函数同宏函数一样将在被调用处进行代码展开，省去了参数压栈、栈帧开辟与回收，结果返回等，从而提高程序运行速度。
  2. 内联函数相比宏函数来说，在代码展开时，会做安全检查或自动类型转换（同普通函数），而宏定义则不会。
  3. 在类中声明同时定义的成员函数，自动转化为内联函数，因此内联函数可以访问类的成员变量，宏定义则不能。
  4. 内联函数在运行时可调试，而宏定义不可以。

- 缺点
  1. 代码膨胀。
     内联是以代码膨胀（复制）为代价，消除函数调用带来的开销。
     如果执行函数体内代码的时间，相比于函数调用的开销较大，那么效率的收获会很少。
     另一方面，每一处内联函数的调用都要复制代码，将使程序的总代码量增大，消耗更多的内存空间。
  2. `inline` 函数无法随着函数库升级而升级。`inline` 函数的改变需要重新编译，不像 `non-inline` 可以直接链接。
  3. 是否内联，程序员不可控。内联函数只是对编译器的建议，是否对函数内联，决定权在于编译器。

##### 虚函数（`virtual`）可以是内联函数（`inline`）吗？

- 虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联。
- 内联是在编译期建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时（运行期）不可以内联。
- `inline virtual` 唯一可以内联的时候是：编译器知道所调用的对象是哪个类（如 `Base::who()`），这只有在编译器具有实际对象而不是对象的指针或引用时才会发生。

##### 虚函数内联使用

```cpp
#include <iostream>

class Base {
public:
    inline virtual void who() {
        std::cout << "I am Base\n";
    }

    virtual ~Base() {}
};

class Derived : public Base {
public:
    inline void who() { // 不写 inline 时隐式内联
        std::cout << "I am Derived\n";
    }
};

int main() {
    // 此处的虚函数 who()，是通过类（Base）的具体对象（b）来调用的，编译期间就能确定了，
    // 所以它可以是内联的，但最终是否内联取决于编译器。
    Base b;
    b.who();
    // 此处的虚函数是通过指针调用的，呈现多态性，需要在运行时期间才能确定，所以不能为内联。
    Base *ptr = new Derived();
    ptr->who();

    // 因为Base有虚析构函数（virtual ~Base() {}），所以 delete 时，
    // 会先调用派生类（Derived）析构函数，再调用基类（Base）析构函数，防止内存泄漏。
    delete ptr;
    ptr = nullptr;

    system("pause");
    return 0;
}
```

#### 友元函数

友元函数是 C++ 中的一个特殊函数，尽管它不是类的成员函数，但却有权访问类的私有和受保护数据。

友元函数是类的非成员函数或普通函数，在类内部使用关键字 `friend` 声明为友元函数。通过将函数声明为友元，所有访问权限均赋予该函数。

关键字 `friend` 仅放在友元函数的函数声明中，而不放在函数定义或调用中。

友元函数的调用方式与普通函数类似。它不能使用对象名称和点运算符来调用。但是，它可以接受对象作为要访问其值的参数。

友元函数可以在类的任何部分声明，即公共、私有或受保护。

#### Run-time Type Information (RTTI) 运行时类型识别

使程序能够使用基类的指针或引用来检查这些指针或引用所指的对象的实际派生类型。

在 `C++` 中，`RTTI` 可用于使用 `dynamic_cast<>` 运算符执行安全类型转换，以及在运行时使用 `typeid` 运算符和 `std::type_info` 类处理类型信息。

`RTTI` 仅适用于多态类，这意味着它们至少有一个虚拟方法。实际上，这不是一个限制，因为基类必须具有虚拟析构函数，以允许派生类的对象在从基指针中删除时执行适当的清理。

`dynamic_cast` 运算符：将基类类型的指针或引用安全地转换为其派生类类型的指针或引用。

`typeid` 运算符：返回指针或引用所指对象的实际类型。

要想让 `RTTI` 的两个运算符能够正常工作，那么基类中必须至少要有一个虚函数，不然这两个运算符工作的结果可能跟预期结果不一样，因为只有虚函数的存在，这两个运算符才会使用指针或引用所绑定的对象的动态类型。

#### Resource Acquisition Is Initialization (RAII) 资源获取即初始化

在 RAII 中，持有资源是类的不变量，并且与对象的生命周期相关联。

资源分配（或获取）由构造函数在对象创建（特别是初始化）期间完成，

而资源释放（释放）在对象销毁（特别是终结）期间由析构函数完成。

优势为提供封装、异常安全性（用于堆栈资源）和局部性（它允许将获取和释放逻辑彼此相邻写入）。

局限性

`RAII` 仅适用于堆栈分配对象获取和释放（直接或间接）的资源，其中具有明确定义的静态对象生命周期。

`RAII` 依赖于在所有可能的执行路径上隐式或显式删除基于堆的对象，以触发其资源释放析构函数（或等效函数）。
这可以通过使用智能指针来管理所有堆对象来实现，而弱指针则用于循环引用的对象。

### 模板

显示具体化

- 因为对于某些特殊类型，可能不适合模板实现，需要重新定义实现，此时就是使用显示具体化的场景

```cpp
template <> void Swap<job> (job &,job &);
```

显示实例化

- 是无论是否有程序用，编译器都会生成一个实例函数

```cpp
template  void  Swap<int> (int ,int);
```

隐式实例化

- 使用模板之前，编译器不生成模板的声明和定义示例，后面有程序用了，编译器才会根据模板生成一个实例函数

### std::async std::thread

https://stackoverflow.com/questions/25814365/when-to-use-stdasync-vs-stdthreads

It's not really an either-or thing - you can use futures (together with promises) with manually created std::threads. Using std::async is a convenient way to fire off a thread for some asynchronous computation and marshal the result back via a future but std::async is rather limited in the current standard. It will become more useful if the suggested extensions to incorporate some of the ideas from Microsoft's PPL are accepted.

Currently, std::async is probably best suited to handling either very long running computations or long running IO for fairly simple programs. It doesn't guarantee low overhead though (and in fact the way it is specified makes it difficult to implement with a thread pool behind the scenes), so it's not well suited for finer grained workloads. For that you either need to roll your own thread pools using std::thread or use something like Microsoft's PPL or Intel's TBB.

You can also use `std::thread` for 'traditional' POSIX thread style code written in a more modern and portable way.

Bartosz Milewski discusses some of the limitations of the way std::async is currently specified in his article Async Tasks in C++11: Not Quite There Yet

One use-case of using std::future over `std::thread` is you want to call a function which returns a value. When you want return value of the function, you can call `get()` method of future.
在 `std::thread` 上使用 std::future 的一个用例是你想调用一个返回值的函数。当需要函数的返回值时，可以调用 future 的 `get()` 方法。

`std::thread` doesn't provide a direct way to get the return value of the function.
`std::thread` 没有提供获取函数返回值的直接方法。

##### 回答 C++ 什么时候要手动调用析构函数

如果在类 CA 中添加了构造函数，或者添加析构函数，就会发现程序会出现错误。

由于 union 里面的东西共享内存，所以不能定义静态、引用类型的变量。

由于在 union 里也不允许存放带有构造函数、析构函数和复制构造函数等的类的对象，但是可以存放对应的类对象指针。

编译器无法保证类的构造函数和析构函数得到正确的调用，由此，就可能出现内存泄漏。

所以，在 C++中使用 union 时，尽量保持 C 语言中使用 union 的风格，尽量不要让 union 带有对象。

```cpp
#include <iostream>

template<class T>
union Forget {
    T value;

    ~Forget() {}
};

struct A {
    ~A() {
        std::cout << "destroy A\n";
    }
};

int main() {
    auto f = Forget<A>{A{}}; // 不会执行A的析构
    // f.value.~A(); // 需要手动调用析构, 否则资源泄露
}
```
注： union 类型的析构函数在执行 body 之后不会调用 variant member 对象的析构函数

