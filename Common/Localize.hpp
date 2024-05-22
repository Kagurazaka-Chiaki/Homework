
#ifndef Localize_HPP
#define Localize_HPP

#include <cstring>
#include <iostream>
#include <unicode/ucnv.h>
#include <unicode/unistr.h>


namespace Localize {

    inline auto convert_utf8_to_gbk(std::string const &utf8, std::string &gbk) -> void {

        UErrorCode status = U_ZERO_ERROR;

        auto utf8_converter = ucnv_open("UTF-8", &status);
        auto gbk_converter = ucnv_open("windows-936", &status); // GBK is often referred to as "windows-936" in ICU

        if (U_FAILURE(status)) {
            std::cerr << "Failed to open converters: " << u_errorName(status) << std::endl;
        }

        // Estimate the size of the buffer needed for the conversion
        int32_t gbk_len = ucnv_fromUChars(gbk_converter, nullptr, 0, icu::UnicodeString::fromUTF8(utf8).getBuffer(), utf8.length(), &status);
        status = U_ZERO_ERROR; // Reset status for actual conversion


        auto gbk_buffer = std::make_unique<char[]>(gbk_len + 9);
        std::memset(gbk_buffer.get(), '\0', gbk_len + 1);

        // Perform the actual conversion
        ucnv_fromUChars(gbk_converter, gbk_buffer.get(), gbk_len + 1, icu::UnicodeString::fromUTF8(utf8).getBuffer(), utf8.length(), &status);

        if (U_FAILURE(status)) {
            std::cerr << "Failed to convert UTF-8 to GBK: " << u_errorName(status) << std::endl;
        } else {
            gbk.assign(gbk_buffer.get(), gbk_len + 1);
        }

        ucnv_close(utf8_converter);
        ucnv_close(gbk_converter);
    }

    inline void ConvertUTF8ToGBK(const std::string &utf8, std::string &gbk) {
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