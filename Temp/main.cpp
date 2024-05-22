/**
 *
**/

#include <unicode/ucnv.h>
#include <unicode/unistr.h>

#include <cstring>

// #include <bits/stdc++.h>

// #include <Eigen/Dense>

class Base {
        int value;

    public:
        Base(int v)
            : value(v) {}

        friend int Fun1(Base &);
        friend int Fun2(const Base &);
        friend int Fun3(Base);
        friend int Fun4(const Base);
};

int Fun1(Base &);
int Fun2(const Base &);
int Fun3(Base);
int Fun4(const Base);



auto main(int argc, char const *argv[]) -> int {

    (void) argc;
    (void) argv;
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

    return 0;
}
