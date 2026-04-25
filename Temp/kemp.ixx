
export module kemp;

#define ANSWER 42

namespace Example_NS {
    int f_internal() {
        return ANSWER;
    }

    export int f() {
        return f_internal();
    }
} // namespace Example_NS