

#include "Localize.hpp"



auto main(int argc, char const *argv[]) -> int {
    (void) argc;
    (void) argv;
    // system("chcp 65001");

    // using ICU to convert between UTF-8 and GBK

    std::string utf8 = "Hello, 世界!"; // Example UTF-8 string
    std::string gbk;

    Localize::ConvertUTF8ToGBK(utf8, gbk);

    // Output GBK bytes as hex for demonstration purposes
    std::cout << "GBK Encoded: ";
    for (unsigned char c: gbk) {
        printf("%02X ", c);
    }
    std::cout << std::endl;

    std::cout << "GBK Decoded: " << gbk << std::endl;

    std::string gbk2;
    Localize::convert_utf8_to_gbk(utf8, gbk2);

    std::cout << "GBK2 Decoded: " << gbk2 << std::endl;

    return 0;
}
