/**
 *
**/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    int n = 0;
    std::cin >> n;
    std::vector<std::string> v;
    while (n--) {
        std::string s;
        std::cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for (auto const &i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}