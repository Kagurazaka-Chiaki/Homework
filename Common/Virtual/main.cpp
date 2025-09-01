// // // hand-rolled "virtual function table" in C++ (single file, minimal, portable)
// // // This demonstrates manual dynamic dispatch using a function-pointer vtable.
// // // It does NOT use C++'s built-in virtual keyword — we implement the layout and
// // // dispatch ourselves to make the mechanism explicit.
// // //
// // // Build (any one of the following):
// // //   g++   -std=c++17 -O2 -Wall -Wextra manual_vtable.cpp -o manual_vtable
// // //   clang++ -std=c++17 -O2 -Wall -Wextra manual_vtable.cpp -o manual_vtable
// // //   cl /std:c++17 /O2 /W4 manual_vtable.cpp
// // //
// // // Run:
// // //   ./manual_vtable   (or manual_vtable.exe on Windows)
// // //
// // // Expected output:
// // //   Base::print  data=42
// // //   Derived::print  data=7 extra=99
// // //   ~Base
// // //   ~Derived

// // #include <iostream>
// // #include <vector>
// // #include <type_traits>
// // #include <cstddef> // offsetof

// // // Forward declares so function pointer types can reference Base
// // struct Base;

// // // Define function-pointer types for our manual vtable
// // using PrintFn   = void (*)(Base* self);
// // using DestroyFn = void (*)(Base* self); // emulate a virtual destructor

// // // The vtable layout we will use
// // struct BaseVTable {
// //     PrintFn   print;
// //     DestroyFn destroy;
// // };

// // // Base object layout: first field is a pointer to its vtable (like a real vptr)
// // struct Base {
// //     BaseVTable* vptr; // manual vptr
// //     int data;
// // };

// // // Derived layout: MUST embed Base as the first member so Base* == &derived.base
// // struct Derived {
// //     Base base; // must be the very first member
// //     int  extra;
// // };

// // // Static sanity checks to ensure our cast assumptions are safe
// // static_assert(std::is_standard_layout<Derived>::value,
// //               "Derived must be standard layout");
// // static_assert(offsetof(Derived, base) == 0,
// //               "Base subobject must be at offset 0 inside Derived");

// // // ----------------------- "virtual" method implementations --------------------

// // // Base::print
// // void Base_print(Base* self) {
// //     std::cout << "Base::print  data=" << self->data << '\n';
// // }

// // // Derived::print (note: receives a Base*; we cast to Derived*)
// // void Derived_print(Base* self) {
// //     auto* d = reinterpret_cast<Derived*>(self);
// //     std::cout << "Derived::print  data=" << d->base.data
// //               << " extra=" << d->extra << '\n';
// // }

// // // Base::~Base (manual)
// // void Base_destroy(Base* self) {
// //     std::cout << "~Base\n";
// //     delete self; // OK because self actually points to a Base allocated by us
// // }

// // // Derived::~Derived (manual)
// // void Derived_destroy(Base* self) {
// //     auto* d = reinterpret_cast<Derived*>(self);
// //     std::cout << "~Derived\n";
// //     delete d; // delete as Derived to release the full object
// // }

// // // ------------------------------ vtable singletons ----------------------------

// // // One vtable per dynamic type
// // BaseVTable g_BaseVTable    { &Base_print,    &Base_destroy    };
// // BaseVTable g_DerivedVTable { &Derived_print, &Derived_destroy };

// // // --------------------------- factory / constructors --------------------------

// // Base* Base_new(int data) {
// //     Base* b = new Base{};
// //     b->vptr = &g_BaseVTable;
// //     b->data = data;
// //     return b;
// // }

// // Derived* Derived_new(int data, int extra) {
// //     Derived* d = new Derived{};
// //     d->base.vptr = &g_DerivedVTable; // install Derived vtable
// //     d->base.data = data;
// //     d->extra = extra;
// //     return d;
// // }

// // // ----------------------------- dispatch helpers ------------------------------

// // inline void call_print(Base* obj)   { obj->vptr->print(obj); }
// // inline void call_destroy(Base* obj) { obj->vptr->destroy(obj); }

// // // ----------------------------------- demo ------------------------------------

// // int main() {
// //     std::vector<Base*> objs;
// //     objs.push_back(Base_new(42));
// //     objs.push_back(reinterpret_cast<Base*>(Derived_new(7, 99))); // upcast

// //     // Dynamic dispatch via our manual vtable
// //     for (auto* o : objs) {
// //         call_print(o);
// //     }

// //     // Manual virtual destructor via vtable->destroy
// //     for (auto* o : objs) {
// //         call_destroy(o);
// //     }

// //     return 0;
// // }

// // /*
// // Notes
// // -----
// // 1) This mirrors how a typical C++ ABI arranges objects with a hidden vptr and
// //    a per-type vtable of function pointers. Compilers add lots more machinery
// //    (RTTI, multiple-inheritance thunks, adjusters, etc.).
// // 2) Because we control allocation, we can ensure the proper delete in our
// //    manual destructor by choosing the correct destroy function per dynamic type.
// // 3) The only strict aliasing-sensitive cast is Base* -> Derived* in overrides;
// //    it is safe here because we guarantee (by layout and construction) that a
// //    Base* either points to a standalone Base or to the first subobject of a
// //    Derived (checked via offsetof(Derived, base)==0).
// // 4) If you want to add more "virtual" methods, just extend BaseVTable with more
// //    function pointers and fill them in g_BaseVTable / g_DerivedVTable.
// // */

// // override_vs_manual_vtable.cpp — one file, two ways to see overriding
// // (A) Built-in C++ virtual + `override`
// // (B) Hand-rolled vtable equivalent (no `virtual`)
// //
// // Build:
// //   # A) C++ virtual version
// //   g++   -std=c++17 -O2 -Wall -Wextra -DUSE_CPP_VIRTUAL override_vs_manual_vtable.cpp -o demo
// //   clang++ -std=c++17 -O2 -Wall -Wextra -DUSE_CPP_VIRTUAL override_vs_manual_vtable.cpp -o demo
// //   cl /std:c++17 /O2 /W4 /DUSE_CPP_VIRTUAL override_vs_manual_vtable.cpp
// //
// //   # B) Manual vtable version
// //   g++   -std=c++17 -O2 -Wall -Wextra override_vs_manual_vtable.cpp -o demo
// //   clang++ -std=c++17 -O2 -Wall -Wextra override_vs_manual_vtable.cpp -o demo
// //   cl /std:c++17 /O2 /W4 override_vs_manual_vtable.cpp
// //
// // Expected output (both variants):
// //   Base::fun
// //   Derived::fun
// //   Base::fun (forced)
// //   ~Base
// //   ~Derived

// #include <type_traits>

// #include <cstddef>
// #include <iostream>

// // ------------------------------- Variant A ----------------------------------
// #ifdef USE_CPP_VIRTUAL

// struct Base {
//     virtual void fun() { std::cout << "Base::fun\n"; }

//     virtual ~Base() { std::cout << "~Base\n"; }
// };

// struct Derived final : Base {
//     void fun() override { std::cout << "Derived::fun\n"; }

//     ~Derived() override { std::cout << "~Derived\n"; }
// };

// // Uncomment to see compile-time override checking in action:
// // struct Bad final : Base {
// //     void fun(int) override { /* mismatched signature — does NOT override */ }
// // }; // ^^^ This line will fail to compile: "does not override any member function"

// int main() {
//     Base *p = new Base();
//     Base *q = new Derived();

//     p->fun();       // Base::fun
//     q->fun();       // Derived::fun  (dynamic dispatch to override)
//     q->Base::fun(); // Force-call Base version (bypasses virtual dispatch)

//     delete p; // ~Base
//     delete q; // ~Derived (virtual dtor)
// }

// // ------------------------------- Variant B ----------------------------------
// #else

// struct Base; // fwd
// using FunFn     = void (*)(Base *);
// using DestroyFn = void (*)(Base *);

// struct VTable {
//     FunFn     fun;
//     DestroyFn destroy;
// };

// struct Base {
//     VTable *vptr; // manual vptr
// };

// struct Derived {
//     Base base; // MUST be first
// };

// static_assert(std::is_standard_layout<Derived>::value, "Derived must be standard layout");
// static_assert(offsetof(Derived, base) == 0, "Base subobject must be at offset 0");

// // "methods"
// void Base_fun(Base *self) {
//     (void) self;
//     std::cout << "Base::fun\n";
// }

// void Derived_fun(Base *self) {
//     (void) self;
//     std::cout << "Derived::fun\n";
// }

// void Base_destroy(Base *self) {
//     std::cout << "~Base\n";
//     delete self;
// }

// void Derived_destroy(Base *self) {
//     std::cout << "~Derived\n";
//     delete reinterpret_cast<Derived *>(self);
// }

// VTable g_BaseVT{&Base_fun, &Base_destroy};
// VTable g_DerivedVT{&Derived_fun, &Derived_destroy};

// Base *Base_new() {
//     Base *b = new Base{};
//     b->vptr = &g_BaseVT;
//     return b;
// }

// Derived *Derived_new() {
//     Derived *d   = new Derived{};
//     d->base.vptr = &g_DerivedVT;
//     return d;
// }

// inline void call_fun(Base *o) {
//     o->vptr->fun(o);
// }

// inline void call_destroy(Base *o) {
//     o->vptr->destroy(o);
// }

// int main() {
//     Base *p = Base_new();
//     Base *q = reinterpret_cast<Base *>(Derived_new());

//     call_fun(p);     // Base::fun
//     call_fun(q);     // Derived::fun (override via vptr)
//     g_BaseVT.fun(q); // Base::fun (forced) — like q->Base::fun()

//     call_destroy(p); // ~Base
//     call_destroy(q); // ~Derived
// }

// #endif

// override_g_return_by_value.cpp — demonstrate adding `A g() override` that returns by value
// Two variants in one file:
//   (A) C++ virtual + override  (define USE_CPP_VIRTUAL)
//   (B) Manual vtable equivalent (no `virtual`)
//
// Build:
//   # A) Built-in virtual/override
//   g++   -std=c++17 -O2 -Wall -Wextra -DUSE_CPP_VIRTUAL override_g_return_by_value.cpp -o demo
//   clang++ -std=c++17 -O2 -Wall -Wextra -DUSE_CPP_VIRTUAL override_g_return_by_value.cpp -o demo
//   cl /std:c++17 /O2 /W4 /DUSE_CPP_VIRTUAL override_g_return_by_value.cpp
//
//   # B) Manual vtable
//   g++   -std=c++17 -O2 -Wall -Wextra override_g_return_by_value.cpp -o demo
//   clang++ -std=c++17 -O2 -Wall -Wextra override_g_return_by_value.cpp -o demo
//   cl /std:c++17 /O2 /W4 override_g_return_by_value.cpp
//
// Expected output (both variants):
//   Base::fun
//   Derived::fun
//   Base::fun (forced)
//   Base::g -> A{0}
//   Derived::g -> A{1}
//   Base::g (forced) -> A{0}
//   ~Base
//   ~Derived

#include <type_traits>

#include <cstddef>
#include <iostream>

// A simple return-by-value payload to make outputs visible
struct A {
    int id;
};

std::ostream &operator<<(std::ostream &os, A const &a) {
    return os << "A{" << a.id << "}";
}

// ------------------------------- Variant A ----------------------------------
#ifdef USE_CPP_VIRTUAL

struct Base {
    virtual void fun() { std::cout << "Base::fun\n"; }

    virtual A g() { return A{0}; }

    virtual ~Base() { std::cout << "~Base\n"; }
};

struct Derived final : Base {
    void fun() override { std::cout << "Derived::fun\n"; }

    A g() override { return A{1}; }

    ~Derived() override { std::cout << "~Derived\n"; }
};

// Uncomment to see override checking for return-by-value rules:
// struct Bad final : Base {
//     // ERROR: return type must be exactly A when returning by value
//     // (covariant returns are only for pointers/references to classes)
//     // B g() override; // will not compile if B != A
// };

int main() {
    Base *p = new Base();
    Base *q = new Derived();

    p->fun();       // Base::fun
    q->fun();       // Derived::fun
    q->Base::fun(); // force base implementation

    std::cout << "Base::g -> " << p->g() << '\n';
    std::cout << "Derived::g -> " << q->g() << '\n'; // dynamic dispatch
    std::cout << "Base::g (forced) -> " << q->Base::g() << '\n';

    delete p; // ~Base
    delete q; // ~Derived (virtual dtor)
}

// ------------------------------- Variant B ----------------------------------
#else

struct Base; // fwd for function pointer parameters

using FunFn     = void (*)(Base *);
using GFn       = A (*)(Base *); // return by value
using DestroyFn = void (*)(Base *);

struct VTable {
    FunFn     fun;
    GFn       g;
    DestroyFn destroy;
};

struct Base {
    VTable *vptr;
};

struct Derived {
    Base base;
};

static_assert(std::is_standard_layout<Derived>::value, "Derived must be standard layout");
static_assert(offsetof(Derived, base) == 0, "Base subobject must be at offset 0");

// Implementations
void Base_fun(Base *) {
    std::cout << "Base::fun\n";
}

A Base_g(Base *) {
    return A{0};
}

void Derived_fun(Base *) {
    std::cout << "Derived::fun\n";
}

A Derived_g(Base *) {
    return A{1};
}

void Base_destroy(Base *self) {
    std::cout << "~Base\n";
    delete self;
}

void Derived_destroy(Base *self) {
    std::cout << "~Derived\n";
    delete reinterpret_cast<Derived *>(self);
}

VTable g_BaseVT{&Base_fun, &Base_g, &Base_destroy};
VTable g_DerivedVT{&Derived_fun, &Derived_g, &Derived_destroy};

Base *Base_new() {
    Base *b = new Base{};
    b->vptr = &g_BaseVT;
    return b;
}

Derived *Derived_new() {
    auto *d      = new Derived{};
    d->base.vptr = &g_DerivedVT;
    return d;
}

inline void call_fun(Base *o) {
    o->vptr->fun(o);
}

inline A call_g(Base *o) {
    return o->vptr->g(o);
}

inline void call_destroy(Base *o) {
    o->vptr->destroy(o);
}

int main() {
    Base *p = Base_new();
    Base *q = reinterpret_cast<Base *>(Derived_new());

    call_fun(p);     // Base::fun
    call_fun(q);     // Derived::fun
    g_BaseVT.fun(q); // Base::fun (forced)

    std::cout << "Base::g -> " << call_g(p) << '\n';
    std::cout << "Derived::g -> " << call_g(q) << '\n';
    std::cout << "Base::g (forced) -> " << g_BaseVT.g(q) << '\n';

    call_destroy(p); // ~Base
    call_destroy(q); // ~Derived
}

#endif

/*
Key notes
--------
1) 当返回值是“按值返回”时，覆写的返回类型必须与基类完全一致（本例都是 A）。
   只有当返回类型是“指针/引用到类类型”时，才允许协变返回类型（covariant return）。
2) 手写 vtable 版本里，我们把 `g` 加入 vtable，并让 `Derived` 的条目指向 `Derived_g`，
   因此 `call_g(q)` 会动态分派到 `Derived_g`，与 `override` 等价。
*/
