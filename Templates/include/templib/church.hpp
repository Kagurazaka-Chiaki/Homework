#include <functional>

template<class A>
using CBool = std::function<A(A, A)>;

template<class A>
CBool<A> ctrue() {
    return [](A x, A y) {
        return x;
    };
}

template<class A>
CBool<A> cfalse() {
    return [](A x, A y) {
        return y;
    };
}

template<class A>
A cifthen(CBool<A> const &z, A x, A y) {
    return z(x, y);
}

template<class A>
CBool<A> cimply(CBool<A> const &p, CBool<A> const &q) {
    return [=](A x, A y) {
        return p(q(x, y), x);
    };
}

template<class A>
CBool<A> cxor(CBool<A> const &p, CBool<A> const &q) {
    return [=](A x, A y) {
        return p(q(y, x), q(x, y));
    };
}
