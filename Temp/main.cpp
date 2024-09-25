/**
 *
**/

#include <unicode/ucnv.h>
#include <unicode/unistr.h>

#include <cstring>
// #include <iomanip>
#include <iostream>

// #include <vector>

// #include <bits/stdc++.h>

// #include <Eigen/Dense>

// class Base {
//         int value;

//     public:
//         Base(int v)
//             : value(v) {}

//         friend int Fun1(Base &);
//         friend int Fun2(const Base &);
//         friend int Fun3(Base);
//         friend int Fun4(const Base);
// };

// int Fun1(Base &);
// int Fun2(const Base &);
// int Fun3(Base);
// int Fun4(const Base);

// Arbitrary Precision Arithmetic
class APA {

    private:
        int len = 64;

        std::unique_ptr<char[]> data;

    public:
        APA() = default;

        explicit APA(int len)
            : len(len) {
            data = std::make_unique<char[]>(len + 1);
            std::memset(data.get(), '\0', len + 1);
            std::memset(data.get(), '0', len);
        }

        // copy
        APA(const APA &other)            = delete;
        APA &operator=(const APA &other) = delete;


        // move
        APA(APA &&other)            = delete;
        APA &operator=(APA &&other) = delete;

        ~APA()                      = default;

        friend std::ostream &operator<<(std::ostream &os, const APA &apa) {
            os << "len: " << apa.len << " data: " << apa.data.get();
            return os;
        }

        auto clear() -> void {
            std::memset(data.get(), '\0', len + 1);
            std::memset(data.get(), '0', len);
        }

        auto read(char const *str) -> void {
            std::memset(data.get(), '\0', len + 1);
            std::memcpy(data.get(), str, std::strlen(str));
        }

        auto from_int(int num) -> void {
            std::memset(data.get(), '\0', len + 1);
            std::sprintf(data.get(), "%d", num);
        }

        auto from_double(double num) -> void {
            std::memset(data.get(), '\0', len + 1);
            std::sprintf(data.get(), "%f", num);
        }
};

auto ModifyCal_Div(double a, double b) -> void {
    auto int_a = static_cast<int>(a);
    auto len   = (int_a % 10) + 1;
    auto str_a = std::make_unique<char[]>(len + 1);
}

#include <filesystem>

auto main(int argc, char const *argv[]) -> int {

    (void) argc;
    (void) argv;

    auto path = std::filesystem::current_path();

    // APA apa(10); // 0000 0000

    // std::cout << apa << std::endl;

    // apa.read("123456789");

    // std::cout << apa << std::endl;

    // apa.from_int(123456789);

    // std::cout << apa << std::endl;

    // apa.from_double(123456789.123456789);

    // std::cout << apa << std::endl;

    // system("chcp 65001");

    // Eigen::MatrixXd mat1(3, 3);

    // Eigen::MatrixXd mat2(3, 3);

    // mat1 << 1, 2, 3, 4, 5, 6, 7, 8, 9;

    // mat1(0, 0) = 1.3;
    // mat2(0, 0) = 1.3;
    // auto k = mat1 == mat2;
    // std::cout << mat1 << '\n'
    //           << k << std::endl;

    // Fun1(1); Error
    // Fun2(1);
    // Fun3(1);
    // Fun4(1);

    // std::cout << 是一个对象

    // 二叉树
    // 后序 dabec
    // 中序 debac
    // 前序

    // int a = 10, b = 20;
    // int &c = b;
    // b = a;
    // int *d = &b;
    // *d = 30;
    // int f = c + *d + a;

    // std::cout << f;

    // int *p0 = (int *)malloc(sizeof(int));
    // *p0 = 6;
    // int *p1 = (int *)malloc(sizeof(int));
    // *p1 = 5;
    // int *p2 = (int *)malloc(sizeof(int));
    // *p2 = 4;
    // int *p3 = (int *)malloc(sizeof(int));
    // *p3 = 3;
    // int *p4 = (int *)malloc(sizeof(int));
    // *p4 = 2;
    // int *p5 = (int *)malloc(sizeof(int));
    // *p5 = 1;

    // auto a = std::vector<int *>{p0, p1, p2, p3, p4, p5};

    // int n = a.size();

    // for (int i = 0; i < n; i++) {
    //     std::cout << a[i] << " -> " << *a[i] << std::endl;
    // }

    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = 0; j < n - 1 - i; j++) {
    //         if (*(a[j]) > *(a[j + 1])) {
    //             std::swap(a[j], a[j + 1]);
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     std::cout << a[i] << " -> " << *a[i] << std::endl;
    // }


    double a = ((-9525.600289 - -12600.000000) / 3150.000000) - 0.00005;
    double b = (-12423.600377 - -12600.000000) / 3150.000000;


    auto d   = log10(-9525.600289 + 12600.000000) - log10(3150.000000);

    auto e   = pow(10, d);

    std::cout << a << " " << b << " " << std::endl;


    a = -9525.600289;
    b = ((-9525.600289 / 3150.0) - (-12600.0 / 3150.0)) * pow(10, static_cast<int>(a) % 10);

    std::cout << b << std::endl;


    return 0;
}
