
#ifndef RTTI_HPP
#define RTTI_HPP

#include <cstddef>
#include <cstdint>

namespace RTTI {

    // 因此 typedef 或 using 允许调整 RTTI 系统的内存占用
    using TypeID_t = size_t;

    // 唯一的整数标识符来创建 TypeID
    static auto generate_id() -> TypeID_t {
        static TypeID_t id_counter = 0;
        return ++id_counter;
    }

    // 使用编译器本身来准确确定偏移量
    template<typename Derived, typename Base>
    static auto compute_pointer_offset() -> ptrdiff_t {
        Derived *derived_ptr = (Derived *) 1;
        Base *base_ptr       = static_cast<Base *>(derived_ptr);
        return (intptr_t) base_ptr - (intptr_t) derived_ptr;
    }

    // 用于存储类型信息
    struct TypeInfo {
        char const *type_name;

        inline auto get_name() const -> char const * {
            return type_name;
        }

        inline auto get_type_data() const -> char const * {
            return (char *) (this + 1);
        }

        inline auto get_type_id() const -> TypeID_t {
            return *(TypeID_t *) (get_type_data() + sizeof(TypeID_t));
        }

        inline auto cast_to(intptr_t ptr, TypeID_t type_id) const -> intptr_t {
            char const *type_data = get_type_data();
            size_t byte_index     = 0;
            ptrdiff_t offset      = 0;

            while (true) {
                TypeID_t size = *reinterpret_cast<TypeID_t const *>(type_data + byte_index);
                byte_index += sizeof(TypeID_t);

                for (TypeID_t i = 0; i < size; ++i) {
                    if (*reinterpret_cast<TypeID_t const *>(type_data + byte_index) == type_id) {
                        return ptr + offset;
                    }
                }

                offset = *reinterpret_cast<ptrdiff_t const *>(type_data + byte_index);

                if (offset == 0) { return 0; }

                byte_index += sizeof(ptrdiff_t);
            }
        }

        inline auto operator==(TypeInfo const &other) const -> bool {
            return get_type_id() == other.get_type_id();
        }

        inline auto operator!=(TypeInfo const &other) const -> bool {
            return get_type_id() != other.get_type_id();
        }
    };

} // namespace RTTI

#endif // RTTI_HPP