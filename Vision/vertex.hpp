//

#ifndef GRAPHICS_VERTEX_HPP
#define GRAPHICS_VERTEX_HPP

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>

#include <ostream>

namespace graphics {
    struct vertex {
        glm::vec3 position;
        glm::vec3 color;
        glm::vec2 texcoord;

        friend bool operator==(vertex const &lhs, vertex const &rhs) {
            return lhs.position == rhs.position && lhs.color == rhs.color && lhs.texcoord == rhs.texcoord;
        }

        friend bool operator!=(vertex const &lhs, vertex const &rhs) {
            return !(lhs == rhs);
        }

        friend bool operator<(vertex const &lhs, vertex const &rhs) {
            return lhs.position.x < rhs.position.x && lhs.position.y < rhs.position.y && lhs.position.z < rhs.position.z;
        }

        friend auto operator<<(std::ostream &os, vertex const &v) -> std::ostream & {
            os << "Position: " << v.position.x << ", " << v.position.y << ", " << v.position.z << std::endl;
            os << "Color: " << v.color.x << ", " << v.color.y << ", " << v.color.z << std::endl;
            os << "Texcoord: " << v.texcoord.x << ", " << v.texcoord.y << std::endl;
            return os;
        }
    };

    struct vertex_hash {
        size_t operator()(vertex const &v) const {
            auto const a = std::hash<glm::vec3>()(v.position);
            auto const b = std::hash<glm::vec3>()(v.color);
            auto const c = std::hash<glm::vec2>()(v.texcoord);
            // NOLINTNEXTLINE
            return ((a ^ (b << 1)) >> 1) ^ (c << 1);
        }
    };

    struct UniformBufferObject {
        alignas(16) glm::mat4 model;
        alignas(16) glm::mat4 view;
        alignas(16) glm::mat4 proj;
    };

} // namespace graphics


#endif // GRAPHICS_VERTEX_HPP