
#ifndef Localize_HPP
#define Localize_HPP

#include <cstdint>
#include <cstring>
#include <iostream>
#include <unicode/ucnv.h>
#include <unicode/unistr.h>


namespace Localize {

    inline auto convert_utf8_to_gbk(std::string &utf8, std::string &gbk) -> void {

        std::cout << "utf8: " << utf8 << std::endl;

        UErrorCode status = U_ZERO_ERROR;

        auto utf8_converter = ucnv_open("UTF-8", &status);
        auto gbk_converter = ucnv_open("windows-936", &status); // GBK is often referred to as "windows-936" in ICU

        if (U_FAILURE(status)) {
            std::cerr << "Failed to open converters: " << u_errorName(status) << std::endl;
            return;
        }
        // Estimate the size of the buffer needed for the conversion
        int32_t gbk_len = ucnv_fromUChars(gbk_converter, nullptr, 0, icu::UnicodeString::fromUTF8(utf8).getBuffer(), utf8.length(), &status);
        // if (U_FAILURE(status)) {
        //     std::cerr << "Failed to estimate buffer size: " << u_errorName(status) << std::endl;
        // }
        status = U_ZERO_ERROR; // Reset status for actual conversion
        std::cout << "GBK length: " << gbk_len << utf8.length() << std::endl;

        auto gbk_buffer = std::make_unique<char[]>(gbk_len);
        std::memset(gbk_buffer.get(), 0, gbk_len);

        // Perform the actual conversion
        ucnv_fromUChars(gbk_converter, gbk_buffer.get(), gbk_len, icu::UnicodeString::fromUTF8(utf8).getBuffer(), utf8.length(), &status);

        if (U_FAILURE(status)) {
            std::cerr << "Failed to convert UTF-8 to GBK: " << u_errorName(status) << std::endl;
        } else {
            // remove 0x3F from the end of the buffer
            while (gbk_buffer[gbk_len - 1] == 0x3F) {
                gbk_len--;
            }
            gbk.assign(gbk_buffer.get(), gbk_len);
        }


        ucnv_close(utf8_converter);
        ucnv_close(gbk_converter);
    }

    inline void ConvertUTF8ToGBK(std::string const &utf8, std::string &gbk) {
        UErrorCode status = U_ZERO_ERROR;
        UConverter *utf8Converter = ucnv_open("UTF-8", &status);
        UConverter *gbkConverter = ucnv_open("windows-936", &status); // GBK is often referred to as "windows-936" in ICU

        if (U_FAILURE(status)) {
            std::cerr << "Failed to open converters: " << u_errorName(status) << std::endl;
            return;
        }

        // Estimate the size of the buffer needed for the conversion
        int32_t gbkLen = ucnv_fromUChars(gbkConverter, nullptr, 0, icu::UnicodeString::fromUTF8(utf8).getBuffer(), utf8.length(), &status);
        status = U_ZERO_ERROR; // Reset status for actual conversion

        // Allocate buffer for GBK string
        char *gbkBuffer = new char[gbkLen + 1];
        std::memset(gbkBuffer, '\0', gbkLen + 1);

        // Perform the actual conversion
        ucnv_fromUChars(gbkConverter, gbkBuffer, gbkLen + 1, icu::UnicodeString::fromUTF8(utf8).getBuffer(), utf8.length(), &status);

        if (U_FAILURE(status)) {
            std::cerr << "Failed to convert UTF-8 to GBK: " << u_errorName(status) << std::endl;
        } else {
            gbk.assign(gbkBuffer, gbkLen);
        }

        delete[] gbkBuffer;
        ucnv_close(utf8Converter);
        ucnv_close(gbkConverter);
    }
}



#endif // Localize_HPP