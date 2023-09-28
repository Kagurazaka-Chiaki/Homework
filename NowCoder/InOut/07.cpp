

#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>


auto gunc(std::stringstream &s) -> std::vector<int> {
    int i = 0;
    std::vector<int> v;
    while (s >> i) {
        v.push_back(i);
    }
    return v;
}

auto func(std::stringstream &s) -> void {
    int sum = 0, temp = 0;
    while (s >> temp) {
        sum += temp;
    }
    std::cout << sum << std::endl;
}

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    std::string line;
    while (getline(std::cin, line)) {
        std::stringstream ss;
        ss << line;
        // func(ss);
        auto vec = gunc(ss);
        // int result = 0;
        // std::for_each(vec.begin(), vec.end(), [&result](int x){ result += x; });
        // cout << result << endl;
        std::cout << std::accumulate(vec.begin(), vec.end(), 0) << std::endl;
    }

    return 0;
}
