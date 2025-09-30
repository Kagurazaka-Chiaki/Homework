#include <iostream>

auto gunc(int const &n) -> void {
    int sum = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        sum += temp;
    }
    std::cout << sum << std::endl;
}

auto func() -> bool {
    int n = 0; // n \in [1, 100]
    std::cin >> n;
    if (n == 0) {
        return false;
    } else {
        gunc(n);
        return true;
    }
}

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    // bool temp = func();
    // while (temp) {
    //     temp = func();
    // }
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        long long sum = 0LL;
        while (n--) {
            long long a;
            std::cin >> a;
            sum += a;
        }
        std::cout << sum << '\n';
    }
}

// 64 位输出请用 printf("%lld")