
#include <iostream>


auto gunc(int const &n) -> void {
    int sum = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        sum += temp;
    }
    std::cout << sum << std::endl;
}

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    int t = 0; // t \in [1, 100]
    std::cin >> t;
    while (t--) {
        int n = 0; // n \in [1, 100]
        std::cin >> n;
        gunc(n);
    }
    return 0;
}