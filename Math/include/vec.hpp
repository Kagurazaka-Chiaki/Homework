//

#ifndef VEC_HPP
#define VEC_HPP

#define _USE_MATH_DEFINES
#include <cmath>


#include <algorithm>
#include <format>
#include <memory>
#include <numeric>
#include <utility>
#include <vector>

namespace math {

    template<int N>
    class mat;

    template<int N>
    class vec {
        private:
            //        1            15
            //        v             v
            // pi = 3.1415926535897932384
            int _precision = std::numeric_limits<double>::digits10;
            // double epsilon_ = std::pow(10, -precision_)
            double _epsilon = std::numeric_limits<double>::epsilon();

            std::unique_ptr<double[]> _v;

            auto swap(vec &other) noexcept -> void {
                std::swap(this->_v, other._v);
            }

        public:
            vec() {
                this->_v = std::make_unique<double[]>(N);
                std::fill_n(this->_v.get(), N, 0.0);
            }

            vec(std::initializer_list<double> init_list) {
                this->_v = std::make_unique<double[]>(N);
                std::fill_n(this->_v.get(), N, 0.0);
                std::copy(init_list.begin(), init_list.end(), this->_v.get());
            }

            vec(std::initializer_list<std::string> init_list) {
                this->_v = std::make_unique<double[]>(N);
                std::transform(
                        init_list.begin(), init_list.end(),
                        this->_v.get(), //
                        [](std::string const &s) {
                            return std::stod(s);
                        }
                );
            }

            // copy constructor
            vec(vec const &other) {
                this->_v = std::make_unique<double[]>(N);
                std::copy(other._v.get(), other._v.get() + N, this->_v.get());
            }

            // move constructor
            vec(vec &&other) noexcept {
                this->_v = std::exchange(other._v, nullptr);
            }

            // copy assignment
            auto operator=(vec const &origin) -> vec & {
                vec(origin).swap(*this);
                return *this;
            }

            // move assignment
            auto operator=(vec &&origin) noexcept -> vec & {
                this->_v = std::exchange(origin._v, nullptr);
                return *this;
            }

            ~vec() noexcept = default;

            auto operator[](std::size_t i) -> double & {
                if (i >= N) {
                    throw std::out_of_range("vec subscript out of range");
                }
                return this->_v[i];
            }

            auto operator[](std::size_t i) const -> double {
                if (i >= N) {
                    throw std::out_of_range("vec subscript out of range");
                }
                return this->_v[i];
            }

            auto operator+() -> vec {
                return vec(*this);
            }

            auto operator-() -> vec {
                std::transform(this->_v.get(), this->_v.get() + N, this->_v.get(), std::negate<>());
                return *this;
            }

            auto operator+=(vec const &other) -> vec & {
                std::transform(_v.get(), _v.get() + N, other._v.get(), _v.get(), std::plus<>());
                return *this;
            }

            auto operator-=(vec const &other) -> vec & {
                std::transform(_v.get(), _v.get() + N, other._v.get(), _v.get(), std::minus<>());
                return *this;
            }

            friend auto operator==(vec const &lhs, vec const &rhs) -> bool {
                return std::equal(
                        lhs._v.get(), lhs._v.get() + N,
                        rhs._v.get(), rhs._v.get() + N,
                        [](double const &x, double const &y) {
                            return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
                        }
                );
            }

            friend auto operator!=(vec const &lhs, vec const &rhs) -> bool {
                return !std::equal(
                        lhs._v.get(), lhs._v.get() + N,
                        rhs._v.get(), rhs._v.get() + N,
                        [](double const &x, double const &y) {
                            return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
                        }
                );
            }

            friend auto operator+(vec const &lhs, vec const &rhs) -> vec {
                auto result = vec();
                std::transform(lhs._v.get(), lhs._v.get() + N, rhs._v.get(), result._v.get(), std::plus<>());
                return result;
            }

            friend auto operator-(vec const &lhs, vec const &rhs) -> vec {
                auto result = vec();
                std::transform(lhs._v.get(), lhs._v.get() + N, rhs._v.get(), result._v.get(), std::minus<>());
                return result;
            }

            friend auto operator*(vec const &v, double val) -> vec {
                auto result = vec();
                std::transform(v._v.get(), v._v.get() + N, result._v.get(), [val](double const &x) { return x * val; });
                return result;
            }

            friend auto operator*(double val, vec const &v) -> vec {
                auto result = vec();
                std::transform(v._v.get(), v._v.get() + N, result._v.get(), [val](double const &x) { return val * x; });
                return result;
            }

            friend auto operator*(vec const &lhs, vec const &rhs) -> mat<N> {
                auto result = mat<N>();
                for (auto i = 0; i < N; ++i) {
                    for (auto j = 0; j < N; ++j) {
                        result[i][j] = lhs[i] * rhs[j];
                    }
                }
                return result;
            }

            friend auto operator/(vec const &v, double val) -> vec {
                auto result = vec();
                std::transform(v._v.get(), v._v.get() + N, result._v.get(), [val](double const &x) { return x / val; });
                return result;
            }

            friend auto operator/(double val, vec const &v) -> vec {
                auto result = vec();
                std::transform(v._v.get(), v._v.get() + N, result._v.get(), [val](double const &x) { return val / x; });
                return result;
            }

            explicit operator std::vector<double>() const {
                auto result = std::vector<double>();
                std::copy(this->_v.get(), this->_v.get() + N, std::back_inserter(result));
                return result;
            }

            explicit operator std::vector<std::string>() const {
                auto result = std::vector<std::string>();
                std::transform(
                        this->_v.get(),
                        this->_v.get() + N,
                        std::back_inserter(result),
                        [this](double const &x) {
                            return std::format("{:.{}f}", x, _precision);
                        }
                );
                return result;
            }

            explicit operator std::string() const {
                auto v = static_cast<std::vector<std::string>>(*this);
                auto result = std::string();
                std::for_each(v.begin(), v.end(), [&result](auto const &s) {
                    result += s + " ";
                });
                return "[ " + result + "]";
            }

            friend auto operator<<(std::ostream &output, vec const &v) -> std::ostream & {
                return output << static_cast<std::string>(v);
            }

            auto push(double const &val) -> vec<N + 1> {
                auto result = vec<N + 1>();
                for (auto i = 0; i < N; ++i) {
                    result[i] = this->_v[i];
                }
                result[N] = val;
                return result;
            }

            auto pop() const -> vec<N - 1> {
                auto result = vec<N - 1>();
                for (auto i = 0; i < N - 1; ++i) {
                    result[i] = this->_v[i];
                }
                return result;
            }

            auto transpose() const -> vec {
                auto result = vec();
                std::copy(this->_v.get(), this->_v.get() + N, result._v.get());
                return result;
            }

            [[nodiscard]] auto norm(int p = 2) const -> double {
                if (p == 0) { // infinity norm
                    return std::fabs(*std::max_element(this->_v.get(), this->_v.get() + N));
                }
                if (p == 1) { // 1-norm
                    return std::accumulate(
                            this->_v.get(), this->_v.get() + N, 0.0,
                            [](double const &x, double const &y) {
                                return x + std::fabs(y);
                            }
                    );
                }
                if (p == 2) { // 2-norm
                    return std::sqrt(std::accumulate(
                            this->_v.get(), this->_v.get() + N, 0.0,
                            [](double const &x, double const &y) {
                                return x + y * y;
                            }
                    ));
                }
                // p-norm
                return std::pow(
                        std::accumulate(
                                this->_v.get(), this->_v.get() + N, 0.0,
                                [p](double const &x, double const &y) {
                                    return x + std::pow(std::fabs(y), p);
                                }
                        ),
                        1.0 / p
                );
            }

            auto unit() const -> vec {
                return (*this) * (1.0 / this->norm());
            }

            auto dot(vec const &other) const -> double {
                return std::inner_product(
                        this->_v.get(), this->_v.get() + N,
                        other._v.get(), 0.0
                );
            }

            auto cross(vec const &other) const -> vec {
                // if constexpr (N != 3) {
                //     throw std::runtime_error("cross product is only defined for 3-dimensional vectors");
                // }
                return vec{
                        this->_v[1] * other._v[2] - this->_v[2] * other._v[1],
                        this->_v[2] * other._v[0] - this->_v[0] * other._v[2],
                        this->_v[0] * other._v[1] - this->_v[1] * other._v[0] //
                };
            }

            auto angle(vec const &other) const -> double {
                return std::acos(this->dot(other) / (this->norm() * other.norm()));
            }

            auto project(vec const &other) const -> vec {
                return other * (this->dot(other) / other.dot(other));
            }

            auto reject(vec const &other) const -> vec {
                return *this - this->project(other);
            }

            auto to_rad() const -> vec {
                return *this * (M_PI / 180.0);
            }

            auto to_deg() const -> vec {
                return *this * (180.0 / M_PI);
            }

            auto is_parallel(vec const &other) const -> bool {
                return this->cross(other).norm() < _epsilon;
            }

            auto is_orthogonal(vec const &other) const -> bool {
                return std::fabs(this->dot(other)) < _epsilon;
            }

            [[nodiscard]] auto is_zero() const -> bool {
                return this->norm() < _epsilon;
            }

            [[nodiscard]] auto is_unit() const -> bool {
                return std::fabs(this->norm() - 1.0) < std::numeric_limits<double>::epsilon();
            }

            static auto e(int i) -> vec {
                if (i < 0 || i >= N) {
                    throw std::runtime_error("index out of bounds");
                }
                auto result = vec();
                result._v[i] = 1.0;
                return result;
            }

            auto householder() const -> mat<N> {
                auto u = *this / this->norm();
                return mat<N>::identity() - 2 * u * u.transpose();
            }

            // R = I - 2 * (I * N) * N
            auto reflect(vec const &norm) const -> vec {
                return *this - 2.0 * (this->dot(norm)) * norm;
            }
    };

} // namespace math

#endif // VEC_HPP
