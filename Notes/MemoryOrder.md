#

##

在语言层面实现对在多处理器中多线程共享内存交互的控制

### C++ 11 Memory Order

`std::memory_order_relaxed`

    Relaxed operation: there are no synchronization or ordering constraints imposed on other reads or writes,
    only this operation's atomicity is guaranteed (see Relaxed ordering below).

`std::memory_order_consume`

    A load operation with this memory order performs a consume operation on the affected memory location:
    no reads or writes in the current thread dependent on the value currently loaded can be reordered before this load.
    Writes to data-dependent variables in other threads that release the same atomic variable are visible in the current thread.
    On most platforms, this affects compiler optimizations only (see Release-Consume ordering below).

    具有此内存顺序的加载操作在受影响的内存位置上执行 consume 操作：在此加载之前，无法对当前线程中依赖于当前加载的值的读取或写入重新排序。
    在当前线程中可以看到对释放相同原子变量的其他线程中的数据因变量的写入。在大多数平台上，这仅影响编译器优化

`std::memory_order_acquire`

    A load operation with this memory order performs the acquire operation on the affected memory location:
    no reads or writes in the current thread can be reordered before this load.
    All writes in other threads that release the same atomic variable are visible in the current thread (see Release-Acquire ordering below).

    具有此内存顺序的 load 操作在受影响的内存位置上执行 acquire 操作：在此 load 之前，当前线程中的任何读取或写入都不能重新排序。
    释放相同原子变量的其他线程中的所有写入在当前线程中都可见

`std::memory_order_release`

    A store operation with this memory order performs the release operation: no reads or writes in the current thread can be reordered after this store.
    All writes in the current thread are visible in other threads that acquire the same atomic variable (see Release-Acquire ordering below)
    and writes that carry a dependency into the atomic variable become visible in other threads that consume the same atomic
    (see Release-Consume ordering below).

    具有此内存顺序的存储操作将执行释放操作：在此存储之后，当前线程中的任何读取或写入都不能重新排序。当前线程中的所有写入在获取相同原子变量的其他线程中可见
    并且将依赖项带入原子变量的写入在使用相同原子的其他线程中可见

`std::memory_order_acq_rel`

    A read-modify-write operation with this memory order is both an acquire operation and a release operation.
    No memory reads or writes in the current thread can be reordered before the load, nor after the store.
    All writes in other threads that release the same atomic variable are visible before the modification
    and the modification is visible in other threads that acquire the same atomic variable.

    具有此内存顺序的 read-modify-write 操作既是 acquire 操作，也是 release 操作。当前线程中的内存读取或写入不能在加载之前或存储之后重新排序。
    在修改之前，释放相同原子变量的其他线程中的所有写入都是可见的，并且修改在获取相同原子变量的其他线程中可见。

`std::memory_order_seq_cst`

    A load operation with this memory order performs an acquire operation, a store performs a release operation,
    and read-modify-write performs both an acquire operation and a release operation,
    plus a single total order exists in which all threads observe all modifications in the same order
    (see Sequentially-consistent ordering below).

    具有此内存顺序的 load 操作执行 acquire 操作，store 执行 release 操作，read-modify-write 同时执行 acquire 操作和 release 操作，
    此外还存在一个总顺序，其中所有线程都以相同的顺序观察所有修改

### Memory Consistency Model 内存一致性模型


#### Sequential Consisten Ordering

对应 `std::memory_order_seq_cst`

默认的内存序，意味着将程序看做是一个简单的序列。如果对于一个原子变量的操作都是顺序一致的，那么多线程程序的行为就像是这些操作都以一种特定顺序被单线程程序执行。

#### Relaxed Ordering

对应 `std::memory_order_relaxed`

宽松对程序次序的要求：这种宽松与 "在无缓存的体系结构中采用的优化" 类似，仅适用于对不同地址的操作对 (opeartion pairs) 间使用。

宽松对写原子性的要求：一些模型允许读操作在 "一个写操作未对所有处理器可见" 前返回值。这种宽松仅适用于基于缓存的体系结构。

不会对内存访问限制顺序，只保证原子操作和修改顺序一致

在 `Relaxed Ordering` 中唯一的要求是在同一线程中，对同一原子变量的访问不可以被重排。

宽松内存排序的典型用途是递增计数器，例如 `std::shared_ptr` 的引用计数器，因为这只需要原子性，但不需要排序或同步

`std::shared_ptr` 的递减计数器需要与析构函数进行 `acquire-release synchronization`

#### Release-Acquire Ordering




#### Sequential Consistency Model