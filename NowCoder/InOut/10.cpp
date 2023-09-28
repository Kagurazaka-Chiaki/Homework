/**
 *
**/

#include <iostream>
#include <sstream>
#include <vector>

auto gunc(std::vector<std::string> &vec, char const &delim) -> void {
    sort(vec.begin(), vec.end());
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (it == vec.end() - 1) {
            std::cout << *it;
        } else {
            std::cout << *it << delim;
        }
    }
    std::cout << std::endl;
}

auto func(std::istringstream &s) -> std::vector<std::string> {
    std::string word;
    std::vector<std::string> v;
    while (getline(s, word, ',')) {
        v.push_back(word);
    }
    return v;
}

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    std::string line;
    while (std::cin >> line) {
        std::istringstream s(line);
        auto vec = func(s);
        gunc(vec, ',');
    }
    return 0;
}
