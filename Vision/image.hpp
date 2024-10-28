
#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "vertex.hpp"
#include <spdlog/spdlog.h>

#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <cstddef>
#include <cstdint>
#include <utility>


enum class ImageFileType {
    NONE,
    PNG,
    JPG,
    BMP,
    TGA,
    HDR,
};

enum class ImageType {
    HEIGHT,
    NORMAL,
    ALBEDO,
    ROUGHNESS,
    METALLIC,
};

class Image {

  private:
  public:
    int w = 0;

    int h = 0;

    int channels = 0;

    uint8_t *data = nullptr;

    size_t size = 0;

    Image(int w, int h, int channels = 3)
        : w(w), h(h) {
        size = w * h * channels;
        data = new uint8_t[size];
    }

    // create image from vector
    Image(std::vector<std::vector<int>> gray_data, int channels = 4)
        : channels(channels) {
        h = gray_data.size();
        w = gray_data[0].size();
        size = w * h * channels;
        this->data = new uint8_t[size];
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                int idx = (i * w + j) * channels;

                int g = gray_data[i][j];
                unsigned char c = (unsigned char) (g * (255.0f / 3.0f));

                data[idx + 0] = c;
                data[idx + 1] = c;
                data[idx + 2] = c;
                data[idx + 3] = 255;
            }
        }
    }

    Image(char const *file_name, int channel_force = 0) {
        if (read_from_file(file_name, channel_force)) {
            spdlog::info("Image loaded from file: {}", file_name);
        } else {
            spdlog::error("Failed to load image from file: {}", file_name);
        }
    }

    // Copy constructor
    Image(Image const &other)
        : w(other.w), h(other.h), channels(other.channels), size(other.size) {
        data = new uint8_t[size];
        std::copy(other.data, other.data + size, data);
    }

    // Copy assignment
    auto operator=(Image const &other) -> Image & {
        if (this != &other) {
            w = other.w;
            h = other.h;
            channels = other.channels;
            size = other.size;
            delete[] data;
            data = new uint8_t[size];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    // Move constructor
    Image(Image &&other) noexcept
        : w(other.w), h(other.h), channels(other.channels), size(other.size), data(other.data) {
        std::exchange(other.data, nullptr);
        std::exchange(other.size, 0);
    }

    // Move assignment
    auto operator=(Image &&other) noexcept -> Image & {
        if (this != &other) {
            w = other.w;
            h = other.h;
            channels = other.channels;
            size = other.size;
            delete[] data;
            data = other.data;
            std::exchange(other.data, nullptr);
            std::exchange(other.size, 0);
        }
        return *this;
    }

    ~Image() {
        spdlog::info("Image destroyed");
        stbi_image_free(data);
    }

    auto read_from_file(char const *file_name, int channel_force = 0) -> bool {
        data = stbi_load(file_name, &w, &h, &channels, channel_force);
        channels = channel_force == 0 ? channels : channel_force;
        return data != nullptr;
    }

    auto get_image_type(char const *file_name) -> ImageFileType {
        auto const &ext = std::string(file_name).substr(std::string(file_name).find_last_of('.') + 1);
        if (ext == "png") {
            return ImageFileType::PNG;
        } else if (ext == "jpg") {
            return ImageFileType::JPG;
        } else if (ext == "bmp") {
            return ImageFileType::BMP;
        } else if (ext == "tga") {
            return ImageFileType::TGA;
        } else if (ext == "hdr") {
            return ImageFileType::HDR;
        } else {
            return ImageFileType::NONE;
        }
    }

    auto write_to_file(char const *file_name) -> bool {
        int success = 0;
        auto const &file_type = get_image_type(file_name);
        switch (file_type) {
            case ImageFileType::PNG:
                success = stbi_write_png(file_name, w, h, channels, data, w * channels);
                break;
            case ImageFileType::JPG:
                success = stbi_write_jpg(file_name, w, h, channels, data, 100);
                break;
            case ImageFileType::BMP:
                success = stbi_write_bmp(file_name, w, h, channels, data);
                break;
            case ImageFileType::TGA:
                success = stbi_write_tga(file_name, w, h, channels, data);
                break;
            case ImageFileType::HDR:
                success = stbi_write_hdr(file_name, w, h, channels, reinterpret_cast<float *>(data));
                break;
            default:
                break;
        }
        if (success) {
            spdlog::info("Image written to file: {}", file_name);
        } else {
            spdlog::error("Failed to write image to file: {}", file_name);
        }
        return success != 0;
    }

    auto show(std::pair<int, int> from, std::pair<int, int> to, int channel = 0) -> std::vector<std::vector<int>> {
        if (from.first < 0 || from.second < 0 || to.first > h || to.second > w) {
            spdlog::error("Invalid Show Image Range");
            return {};
        }
        auto res = std::vector<std::vector<int>>(to.first - from.first, std::vector<int>(to.second - from.second));
        for (int i = from.first; i < to.first; ++i) {
            for (int j = from.second; j < to.second; ++j) {
                int index = (i * w + j) * channels + channel;
                res[i - from.first][j - from.second] = data[index];
            }
        }
        return res;
    }

    auto height_map_to_vertex(double const max_height) -> std::vector<graphics::vertex> {
        auto vertices = std::vector<graphics::vertex>();

        auto map_height = [](uint8_t const *data, int w, int h, int channels, int i, int j) -> float {
            int index = (i * w + j) * channels;
            return data[index] / 255.0f;
        };

        auto map_width = [](int w, int h, int i, int j) -> float {
            return j / (float) w;
        };


        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                int index = (i * w + j) * channels;
                auto x = i;
                auto y = j;
                auto z = data[index] / 255.0f * max_height;
                auto color = glm::vec3(data[index] / 255.0f, data[index] / 255.0f, data[index] / 255.0f);
                auto texcoord = glm::vec2(j / (float) w, i / (float) h);
                vertices.push_back({glm::vec3(x, y, z), color, texcoord});
            }
        }

        return vertices;
    }
};

#endif // IMAGE_HPP
