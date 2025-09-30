#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string line;
        std::getline(std::cin >> std::ws, line);
        line.erase(std::remove_if(line.begin(), line.end(), [](char c){
            return std::isspace(c);
        }), line.end());
        std::reverse(line.begin(), line.end());
        std::cout << line << '\n';
    }
    return 0;
}
// 64 位输出请用 printf("%lld")