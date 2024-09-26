/**
 *
**/

#include <iostream>
#include <sstream>
#include <string>
#include <tuple>

auto main(int argc, char const *argv[]) -> int {
    (void) argc;
    (void) argv;
    /* code */
    int t = 0;
    std::cin >> t;
    std::cout << t << '\n';

    std::string line;
    while (t) {

        int n = 0;
        std::cin >> n;
        std::cout << "n:" << n << '\n';

        std::getline(std::cin, line);
        std::cout << "t:" << t << line << '\n';

        std::getline(std::cin, line);
        std::cout << "t:" << t << line << '\n';

        t = t - 1;
    }


    return 0;
}
