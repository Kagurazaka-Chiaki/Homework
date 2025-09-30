#include <iomanip>
#include <iostream>
#include <numbers>

// double const PI = 3.1415926535897;

int main() {
    // double n;
    // std::cin >> n;
    // printf("%lf", n * n * PI);

    double r;
    std::cin >> r;
    // 计算圆的面积
    double area = r * r * std::numbers::pi;
    // 设置输出精度为小数点后三位
    std::cout << std::fixed << std::setprecision(6) << area << std::endl;
    return 0;
}

// 64 位输出请用 printf("%lld")