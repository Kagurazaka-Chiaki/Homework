//

#include <iostream>
#include <sstream>

auto gunc(std::stringstream &s, int const &n) -> void {
    int sum = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        s >> temp;
        sum += temp;
    }
    std::cout << sum << std::endl;
}

auto func(std::stringstream &s) -> void {
    int n = 0;
    s >> n;
    gunc(s, n);
}

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    std::string line;
    while (getline(std::cin, line)) {
        std::stringstream ss;
        ss << line;
        func(ss);
    }

    return 0;
}