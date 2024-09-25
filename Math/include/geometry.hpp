#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include "vec.hpp"
#include <initializer_list>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

namespace math {

    template<int N>
    class point {
        std::unique_ptr<double[]> _data;

      public:
        point()
            : _data(std::make_unique<double[]>(N)) {
            std::fill_n(_data.get(), N, 0.0);
        }

        explicit point(std::initializer_list<double> const &init_list)
            : _data(std::make_unique<double[]>(N)) {
            std::copy_n(init_list.begin(), N, _data.get());
        }

        // copy constructor
        point(point const &other)
            : _data(std::make_unique<double[]>(N)) {
            std::copy_n(other._data.get(), N, _data.get());
        }

        // copy assignment
        auto operator=(point const &other) -> point & {
            point(other).swap(*this);
            return *this;
        }

        // move constructor
        point(point &&other) noexcept
            : _data(std::exchange(other._data, nullptr)) {}

        // move assignment
        auto operator=(point &&other) noexcept -> point & {
            this->_data = std::exchange(other._data, nullptr);
            return *this;
        }

        ~point() noexcept = default;

        auto operator[](std::size_t i) -> double & {
            if (i >= N) {
                throw std::out_of_range("point subscript out of range");
            }
            return this->_data[i];
        }

        auto operator[](std::size_t i) const -> double {
            if (i >= N) {
                throw std::out_of_range("point subscript out of range");
            }
            return this->_data[i];
        }

        explicit operator std::string() const {
            auto result = std::string{"("};
            std::for_each(_data.get(), _data.get() + N, [&result](double const &d) {
                result += std::to_string(d) + ", ";
            });
            return result.replace(result.size() - 2, 2, ")");
        }

        friend auto operator<<(std::ostream &os, point const &p) -> std::ostream & {
            return os << static_cast<std::string>(p);
        }
    };

    template<int N>
    inline auto distance(point<N> const &lhs, point<N> const &rhs) -> double {
        double sum = 0.0;
        for (int i = 0; i < N; ++i) {
            sum += std::pow(lhs[i] - rhs[i], 2);
        }
        return std::sqrt(sum);
    }

    template<int N>
    inline auto triangle_area(point<N> const &p1, point<N> const &p2, point<N> const &p3) -> double {
        if (N == 3 || N == 2) {
            auto a = distance(p1, p2);
            auto b = distance(p2, p3);
            auto c = distance(p3, p1);
            auto s = (a + b + c) / 2;
            return std::sqrt(s * (s - a) * (s - b) * (s - c));
        }
        throw std::invalid_argument("Only support 2D and 3D points");
    }

    template<int N>
    inline auto triangle_area(vec<N> const &p1, vec<N> const &p2, vec<N> const &p3) -> double {
        if (N == 3 || N == 2) {
            auto a = distance(p1, p2);
            auto b = distance(p2, p3);
            auto c = distance(p3, p1);
            auto s = (a + b + c) / 2;
            return std::sqrt(s * (s - a) * (s - b) * (s - c));
        }
        throw std::invalid_argument("Only support 2D and 3D points");
    }

    class line {
        vec<3> _p;
        vec<3> _v;

      public:
        line(vec<3> const &p, vec<3> const &v)
            : _p(p), _v(v) {}

        line(std::initializer_list<double> const &p, std::initializer_list<double> const &v)
            : _p(p), _v(v) {}

        auto point() const -> vec<3> {
            return _p;
        }

        auto direction() const -> vec<3> {
            return _v;
        }
    };

    class triangle {

        vec<3> _a;
        vec<3> _b;
        vec<3> _c;

      public:
        triangle(vec<3> const &a, vec<3> const &b, vec<3> const &c)
            : _a(a), _b(b), _c(c) {}

        triangle(std::initializer_list<double> const &a, std::initializer_list<double> const &b, std::initializer_list<double> const &c)
            : _a(a), _b(b), _c(c) {}

        auto A() const -> vec<3> {
            return _a;
        }

        auto B() const -> vec<3> {
            return _b;
        }

        auto C() const -> vec<3> {
            return _c;
        }

        auto area() const -> double {
            return triangle_area(_a, _b, _c);
        }

        auto normal() const -> vec<3> {
            return (_b - _a).cross(_c - _a).unit();
        }
    };

    class plane {

        vec<3> _normal;
        vec<3> _point;

      public:
        plane(vec<3> const &normal, vec<3> const &point)
            : _normal(normal), _point(point) {}

        plane(std::initializer_list<double> const &normal,
              std::initializer_list<double> const &point)
            : _normal(normal), _point(point) {}

        auto project(vec<3> const &p) const -> vec<3> {
            auto v = p - _point;
            auto d = _normal.dot(v);
            return p - d * _normal;
        }
    };

    inline auto is_project_in_triangle(vec<3> const &p, triangle const &tri) -> bool {
        auto const &n = tri.normal();
        // std::cout << "n: " << n << std::endl;

        auto const &t = (n.dot(p - tri.A())) / (n.dot(n));
        // std::cout << "t: " << t << std::endl;

        auto const &h = p - t * n;
        // std::cout << "h: " << h << std::endl;

        auto const &v_ab = tri.B() - tri.A(); // b - a
        auto const &v_ac = tri.C() - tri.A(); // c - a
        auto const &v_ap = p - tri.A();       // p - a

        // v_ap = u * v_ab + v * v_ac -> solve u and v

        // v_ap * v_ab = (u * v_ab + v * v_ac) * v_ab
        // v_ap * v_ab = u * (v_ab * v_ab) + v * (v_ac * v_ab)
        auto const &dot_ap_ab = v_ap.dot(v_ab);
        auto const &dot_ab_ab = v_ab.dot(v_ab);
        auto const &dot_ac_ab = v_ac.dot(v_ab);

        // v_ap * v_ac = (u * v_ab + v * v_ac) * v_ac
        // v_ap * v_ac = u * (v_ab * v_ac) + v * (v_ac * v_ac)
        auto const &dot_ap_ac = v_ap.dot(v_ac);
        auto const &dot_ab_ac = v_ab.dot(v_ac);
        auto const &dot_ac_ac = v_ac.dot(v_ac);

        // dot_ap_ab = u * dot_ab_ab + v * dot_ac_ab
        // dot_ap_ac = u * dot_ab_ac + v * dot_ac_ac
        // [dot_ab_ab, dot_ac_ab] [u] = [dot_ap_ab]
        // [dot_ab_ac, dot_ac_ac] [v] = [dot_ap_ac]

        auto const &det = dot_ab_ab * dot_ac_ac - dot_ac_ab * dot_ab_ac;

        auto const &u = (dot_ap_ab * dot_ac_ac - dot_ac_ab * dot_ap_ac) / det;
        if (u < 0 || u > 1) {
            return false;
        }
        auto const &v = (dot_ap_ac * dot_ab_ab - dot_ab_ac * dot_ap_ab) / det;
        if (v < 0 || v > 1) {
            return false;
        }

        return u + v <= 1;
    }

    // inline auto ray_triangle_intersection(vec<3> const &v1, vec<3> const &v2, vec<3> const &v3, vec<3> const &o, vec<3> const &dir) -> bool {
    //     auto const &e1 = v2 - v1;
    //     auto const &e2 = v3 - v1;
    //     auto const &det = dir.cross(e2).dot(e1);
    // }

} // namespace math

#endif // GEOMETRY_HPP