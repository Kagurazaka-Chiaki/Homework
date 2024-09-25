# Run-time Type Information (RTTI) 运行时类型识别


[Dynamic Casting](https://www.learncpp.com/cpp-tutorial/dynamic-casting/)

[RTTI](https://kahncode.com/2019/09/24/c-tricks-fast-rtti-and-dynamic-cast/)

#### `dynamic_cast` 与 `static_cast`

何时使用 `static_cast` 与 `dynamic_cast`? 

除非要向下转换，否则使用 `static_cast`，在这种情况下，`dynamic_cast` 通常是更好的选择。
但是，还应该考虑完全避免 `*_cast`，而只使用 `virtual function`。

#### 向下转换与虚拟函数

有一些开发人员认为 `dynamic_cast` 是邪恶的，表明类设计很糟糕。相反，这些程序员说你应该使用虚拟函数。

一般来说，使用 `virtual function` 应该比 `downcast` 更可取。但是，有时 `downcast` 是更好的选择：

- 当无法修改基类以添加虚函数时（例如，因为基类是标准库的一部分）
- 当需要访问特定于派生类的内容时（例如，仅存在于派生类中的访问函数）
- 当将虚函数添加到基类没有意义时（例如，基类没有合适的值返回）。
  如果不需要实例化 `Base Class`，那么使用纯 `virtual function` 可能是一个选项。

#### 关于 `dynamic_cast` 和 `RTTI` 的警告

运行时类型信息 (`RTTI`) 是 `C++` 的一项功能，可在运行时公开有关对象数据类型的信息。`dynamic_cast` 利用此功能。
由于 `RTTI` 具有相当大的空间性能成本，因此某些编译器允许您关闭 `RTTI` 作为优化。不用说，如果这样做，`dynamic_cast` 将无法正常运行。

然而，在实践中，大多数游戏引擎都有广泛的 `RTTI` 和内省系统 (`Introspection System`)，并广泛使用它。`Unreal Engine` 在其对象系统中使用代码生成来解决这个问题。

#### 构建解决方案


`TypeID`：单个类型的唯一标识

`TypeData`：执行动态强制转换所需的信息

`TypeInfo`：包含 `TypeID`、类型名称和 `TypeData` 的结构体

必须向多态类型添加至少一个 `virtual method`，以便在运行时检索类型信息。这是不可避免的。

类型信息本身应包含足够的信息来识别类型、其名称以及执行动态强制转换所需的所有信息。

为了获得最佳性能，整个信息必须在内存中连续，因此我们将避免任何类型的链表和指针。

因此，`dynamic_cast` 的成本将是调用虚拟方法、加载类型 `info` 和迭代连续内存区域的成本。

