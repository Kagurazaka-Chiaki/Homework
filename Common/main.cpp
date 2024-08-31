

#include "Localize.hpp"

#include <iostream>
#include <vector>


#if WIN32
    #include <windows.h>
#endif


auto main(int argc, char const *argv[]) -> int {
    (void) argc;
    (void) argv;
    // system("chcp 65001");

#if WIN32
    SetConsoleOutputCP(936);
#endif

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

    std::cout << "GBK2 Encoded: ";
    for (unsigned char c: gbk2) {
        printf("%02X ", c);
    }
    std::cout << std::endl;

    std::cout << "GBK2 Decoded: " << gbk2 << std::endl;

    std::vector<unsigned char> gbk3 = {
            0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x2C,
            0x20, 0xCA, 0xC0, 0xBD, 0xE7, 0x21,
            '\0'
    };
    std::cout << "GBK3 Decoded: " << gbk3.size() << ": ";
    for (unsigned char c: gbk3) {
        printf("%02X ", c);
    }
    std::cout << std::endl;

    std::cout << gbk3.data() << std::endl;

    return 0;
}
