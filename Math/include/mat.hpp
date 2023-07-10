//

#ifndef MAT_HPP
#define MAT_HPP

#define _USE_MATH_DEFINES
#include <cmath>

#include <algorithm>
#include <array>
#include <format>
#include <memory>
#include <numeric>
#include <utility>
#include <vector>

namespace math {

    template<int N>
    class vec;

    template<int N>
    class mat {
        private:
            //        1            15
            //        v             v
            // pi = 3.1415926535897932384
            int _precision = std::numeric_limits<double>::digits10;
            // double epsilon_ = std::pow(10, -precision_)
            double _epsilon = std::numeric_limits<double>::epsilon();

            std::array<std::array<double, N>, N> _data = {{0.0}};

            auto swap(mat &other) noexcept -> void {
                std::swap(this->_data, other._data);
            }

        public:
            mat() = default;

            mat(std::initializer_list<std::initializer_list<double>> const &data) {
                std::size_t i = 0;
                std::for_each(data.begin(), data.end(), [this, &i](auto const &row) {
                    if (row.size() != N) {
                        throw std::invalid_argument("invalid initializer list");
                    }
                    std::size_t j = 0;
                    std::for_each(row.begin(), row.end(), [this, &i, &j](auto const &col) {
                        if (std::isnan(col) or std::isinf(col)) {
                            throw std::invalid_argument("invalid initializer element");
                        } else {
                            this->_data[i][j] = col;
                        }
                        ++j;
                    });
                    ++i;
                });
            }

            // copy constructor
            mat(mat const &other) {
                this->_data = other._data;
            }

            // move constructor
            mat(mat &&other) noexcept {
                this->_data = std::exchange(other._data, {});
            }

            // copy assignment operator
            auto operator=(mat const &origin) -> mat & {
                mat(origin).swap(*this);
                return *this;
            }

            // move assignment operator
            auto operator=(mat &&origin) noexcept -> mat & {
                this->_data = std::exchange(origin._data, {});
                return *this;
            }

            ~mat() noexcept = default;

            [[maybe_unused]] static auto zeros() -> mat {
                return mat();
            }

            static auto identity() -> mat {
                auto result = mat();
                for (auto i = 0; i < N; ++i) {
                    result[i][i] = 1.0;
                }
                return result;
            }

            auto operator[](int const &index) -> std::array<double, N> & {
                return this->_data[index];
            }

            auto operator[](int const &index) const -> std::array<double, N> const & {
                return this->_data[index];
            }

            // auto operator()(int const &row, int const &col) -> double & {
            //     return this->_data[row][col];
            // }
            //
            // auto operator()(int const &row, int const &col) const -> double const & {
            //     return this->_data[row][col];
            // }

            auto row(std::size_t const &index) const -> vec<N> {
                auto result = vec<N>();
                for (auto i = 0; i < N; ++i) {
                    result[i] = this->_data[index][i];
                }
                return result;
            }

            auto col(std::size_t const &index) const -> vec<N> {
                auto result = vec<N>();
                for (auto i = 0; i < N; ++i) {
                    result[i] = this->_data[i][index];
                }
                return result;
            }

            friend auto operator==(mat const &lhs, mat const &rhs) -> bool {
                auto lhs_vec = static_cast<vec<N * N>>(lhs);
                auto rhs_vec = static_cast<vec<N * N>>(rhs);
                return lhs_vec == rhs_vec;
            }

            friend auto operator!=(mat const &lhs, mat const &rhs) -> bool {
                auto lhs_vec = static_cast<vec<N * N>>(lhs);
                auto rhs_vec = static_cast<vec<N * N>>(rhs);
                return lhs_vec != rhs_vec;
            }

            friend auto operator+(mat const &lhs, mat const &rhs) -> mat {
                auto result = mat();
                for (auto i = 0; i < N; ++i) {
                    for (auto j = 0; j < N; ++j) {
                        result[i][j] = lhs[i][j] + rhs[i][j];
                    }
                }
                return result;
            }

            friend auto operator-(mat const &lhs, mat const &rhs) -> mat {
                auto result = mat();
                for (auto i = 0; i < N; ++i) {
                    for (auto j = 0; j < N; ++j) {
                        result[i][j] = lhs[i][j] - rhs[i][j];
                    }
                }
                return result;
            }

            friend auto operator-(mat const &m) -> mat {
                auto result = mat();
                for (auto i = 0; i < N; ++i) {
                    for (auto j = 0; j < N; ++j) {
                        result[i][j] = -m[i][j];
                    }
                }
                return result;
            }

            friend auto operator*(mat const &lhs, mat const &rhs) -> mat {
                auto result = mat();
                for (auto i = 0; i < N; ++i) {
                    for (auto j = 0; j < N; ++j) {
                        for (auto k = 0; k < N; ++k) {
                            result[i][j] += lhs[i][k] * rhs[k][j];
                        }
                    }
                }
                return result;
            }

            friend auto operator*(mat const &lhs, vec<N> const &rhs) -> vec<N> {
                auto result = vec<N>();
                for (auto i = 0; i < N; ++i) {
                    for (auto j = 0; j < N; ++j) {
                        result[i] += lhs[i][j] * rhs[j];
                    }
                }
                return result;
            }

            friend auto operator*(vec<N> const &lhs, mat const &rhs) -> vec<N> {
                auto result = vec<N>();
                for (auto i = 0; i < N; ++i) {
                    for (auto j = 0; j < N; ++j) {
                        result[i] += lhs[j] * rhs[j][i];
                    }
                }
                return result;
            }

            friend auto operator*(mat const &lhs, double const &val) -> mat {
                auto result = mat();
                for (auto i = 0; i < N; ++i) {
                    for (auto j = 0; j < N; ++j) {
                        result[i][j] = lhs[i][j] * val;
                    }
                }
                return result;
            }

            friend auto operator*(double const &val, mat const &rhs) -> mat {
                auto result = mat();
                for (auto i = 0; i < N; ++i) {
                    for (auto j = 0; j < N; ++j) {
                        result[i][j] = val * rhs[i][j];
                    }
                }
                return result;
            }

            friend auto operator/(mat const &lhs, double const &val) -> mat {
                auto result = mat();
                for (auto i = 0; i < N; ++i) {
                    for (auto j = 0; j < N; ++j) {
                        result[i][j] = lhs[i][j] / val;
                    }
                }
                return result;
            }

            friend auto operator/(double const &val, mat const &rhs) -> mat {
                auto result = mat();
                for (auto i = 0; i < N; ++i) {
                    for (auto j = 0; j < N; ++j) {
                        result[i][j] = val / rhs[i][j];
                    }
                }
                return result;
            }

            explicit operator vec<N * N>() const {
                auto result = vec<N * N>();
                for (auto i = 0; i < N; ++i) {
                    for (auto j = 0; j < N; ++j) {
                        result[i * N + j] = this->_data[i][j];
                    }
                }
                return result;
            }

            explicit operator std::vector<std::vector<double>>() const {
                auto result = std::vector<std::vector<double>>();
                for (auto i = 0; i < N; ++i) {
                    result.emplace_back(this->_data[i].begin(), this->_data[i].end());
                }
                return result;
            }

            explicit operator std::vector<std::vector<std::string>>() const {
                auto row = std::vector<std::vector<std::string>>();
                std::transform( //
                        this->_data.begin(), this->_data.end(), std::back_inserter(row),
                        [this](auto const &row) { //
                            auto col = std::vector<std::string>();
                            std::transform( //
                                    row.begin(), row.end(), std::back_inserter(col),
                                    [this](auto const &val) {
                                        return std::format("{:.{}f}", val, _precision);
                                    }
                            );
                            return col;
                        }
                );
                return row;
            }

            explicit operator std::string() const {
                auto v = std::vector<std::vector<std::string>>(*this);
                auto result = std::string();
                std::for_each(v.begin(), v.end(), [&result](auto const &row) {
                    result += std::format(
                            "[{} ]\n",                                     //
                            std::accumulate(                               //
                                    row.begin(), row.end(), std::string(), //
                                    [](auto const &lhs, auto const &rhs) {
                                        return lhs + " " + rhs;
                                    } //
                            )
                    );
                });
                return "[ \n" + result + "]\n";
            }

            friend auto operator<<(std::ostream &os, mat const &m) -> std::ostream & {
                return os << std::string(m);
            }

            auto transpose() const -> mat {
                auto result = mat();
                for (auto i = 0; i < N; ++i) {
                    for (auto j = 0; j < N; ++j) {
                        result[i][j] = this->_data[j][i];
                    }
                }
                return result;
            }
    };

} // namespace math

#endif // MAT_HPP
