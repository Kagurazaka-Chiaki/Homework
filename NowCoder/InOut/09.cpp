/**
 *
**/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto gunc(std::vector<std::string> &vec) -> void {
    sort(vec.begin(), vec.end());
    for (auto const &i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

auto func(std::stringstream &s) -> std::vector<std::string> {
    std::string i;
    std::vector<std::string> v;
    while (s >> i) {
        v.push_back(i);
    }
    return v;
}

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    std::string line;
    while (getline(std::cin, line)) {
        std::stringstream s;
        s << line;
        auto vec = func(s);
        gunc(vec);
    }
    return 0;
}
