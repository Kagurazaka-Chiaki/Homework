

/**
 *
**/

#include <cstdio>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#if WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define N    3 + 1
#define Y(n) ((N + 1) * n) // NOLINT

// |        | ->
// aaaaabbbbbaaa -> n = 5 + 5 + 3 = 13
// a = 10 // \in N
// b = 3 // -3

// sub str (a + b) = target

// a = 5
// b = 5
// aaaaabbbbb
// aaaabbbbba
// aaabbbbbaa
// aabbbbbaaa
// res = 4

// n - () + 1

auto print_vec(std::vector<int> vec) {
    for (auto const &v: vec) {
        printf("[%d]", v);
    }
    printf("\n");
}

auto fun(int target, std::string const &s, int N_a, int N_b) -> int {

    int n = s.length();

    //
    int count = 0;
    int k     = n - (N_a + N_b) + 1;
    for (int i = 0; i < k; ++i) { // O(n)
        int ka = 0;
        int kb = 0;
        for (int j = 0; j < N_a + N_b; ++j) { // O(n)
            if (s[j] == 'a') {
                ka++;
            }
            if (s[j] == 'b') {
                kb++;
            }
        }
        if (ka + kb == target) {
            count++;
        }
    } // O(n^2)
    return count;
}

class B {
    int n;

  public:
    void show() {
        std::cout << "***";
    }
};

class A : public B {
  public:
    void show() {
        std::cout << "###";
    }
};

static constexpr int k = 10;

extern "C" {
void foo(int) {
}
}

// 由GNU C++汇编生成的改编后的函数名规则如下
/**
 * 每个改编后的函数名（除了main函数）以2个下划线（__）开始，后跟字母Z、
    一个数值和函数名在跟着形参列表的编码(没有形参就不用了)。字母Z后的数值表示函数名称中字符的个数。例如，函数
    int donothing(char a, int b, float &c, double &d)
在它的函数名中有9个字符，所以改编后名字的前缀是__Z9。然后，
接着跟着函数名，后跟有它的形参列表的编码。
在函数donothing的形参列表中char表示为c，
int表示为i, float &表示为 Rf， double &表示为Rd。所以最终汇编形成的函数名为：
__Z9donothingciRfRd
**/

auto main(int argc, char const *argv[]) -> int {
    (void) argc;
    (void) argv;

    {
        auto z = 2 * (N + Y(5 + 1)); //
        printf("z = %d\n", z);       // 输出: z = 60
    }

    // k = 20; // NOLINT
    // std::string s = "aaaaabbbbbaaa";
    // auto res = fun(10, s, 5, 5);
    // printf("res %d\n", res);

    {
        /**
        * 解释: 该代码演示了C++中类的继承和多态性。
        * 类A继承自类B, 并重写了show()方法。
        * 在main函数中, 通过基类指针p指向派生类对象oa, 并调用show()方法。
        * 输出结果为"###", 表示调用了派生类A的show()方法。
        **/
        A  oa;
        B *p = &oa;
        p->show();
    }

    {
        /**
         * 解释: 该代码演示了C++中指针和数组的用法。
         * 定义了一个整数数组`intArray`, 然后将指针`p`指向数组的末尾。
         * 最后输出数组的第二个元素和最后一个元素的值。
         * 注意: 在C++中, 数组名可以被视为指向数组首元素的指针。
        **/
        int  intArray[] = {1, 2, 3, 4, 5};
        int *p          = (int *) (&intArray + 1);
        printf("%d, %d\n", *(intArray + 1), *(p - 1)); // 输出: 2, 5
    }

    {
        /**
         * 解释: 该代码演示了C++中整数溢出的情况。
         * 定义了一个短整型变量i, 赋值为65537, 然后将其加1赋值给整型变量j。
         * 输出结果为i=65537,j=65538, 说明短整型的范围被超出了。
         * 注意: 在C++中, 短整型的最大值为32767, 因此当i超过这个值时会发生溢出。
        **/
        // NOLINTNEXTLINE
        short i = 65537;
        int   j = i + 1;
        printf("i=%d,j=%d\n", i, j);
    }

    {
        /**
         * 解释: 该代码演示了C++中整数的前导零表示法。
         * 定义了一个整数变量a, 赋值为011, 然后输出其自增后的值。
         * 注意: 在C++中, 前导零表示八进制数, 因此011实际上是八进制的9。
         * 输出结果为10, 因为自增操作将9加1得到10。
        **/
        int a = 011;
        printf("%d\n", ++a);
    }

    {
        /**
        1. int k = 3, s[2] 声明了变量 k 并初始化为 3, 同时声明了一个长度为 2 的整型数组 s
        2. s[0] = k 将 k 的值 3 赋给数组第一个元素
        3. k = s[1] * 10 试图使用数组的第二个元素 s[1], 但 s[1] 从未被初始化
        在 C/C++ 中, 未初始化的数组元素是随机值（垃圾值）。s[1] 的值是不确定的,
        **/
        int k = 3, s[2];
        s[0]  = k;
        k     = s[1] * 10;
        printf("%d\n", k);
    }

    {
        // 1. 首先k=1
        // 2. 由于||的优先级高于逗号运算符,所以先计算k--||k
        // 3. k--||k中,先计算左操作数k--(此时使用k的值1,然后k减1变为0)
        // 4. 因为左操作数为1(非0),所以整个逻辑或表达式结果为1,右操作数k不再计算
        // 5. 逗号运算符取右操作数k++作为整个表达式的值(此时k为0,运算后k变为1)
        // 6. 最终k的值为1
        int k = 1;
        k-- || k, k++;
        printf("%d\n", k); // 输出: 1
        // 解释: 在C++中, 逻辑或运算符(||)是短路运算符。
        // 当左侧表达式为真时, 右侧表达式不会被求值
    }

    {
        /**
         * 解释: lambda表达式的使用示例。
         * 该代码定义了一个递归lambda函数`f`, 用于计算两个整数的和。
         * 通过按位异或和与运算来实现加法, 直到没有进位为止。
         * 输出结果为8和11, 分别是3+5和5+6的和。
         * 注意: lambda表达式的递归调用需要使用`std::function`来定义。
         * 这是因为C++标准不允许直接在lambda内部递归调用自身。
        **/
        std::function<int(int, int)> f = [&](int a, int b) -> int {
            if (b == 0) { return a; }
            int k     = a ^ b;
            int carry = (a & b) << 1;
            return f(k, carry);
        };

        std::cout << f(3, 5) << std::endl; // Output: 8
        std::cout << f(5, 6) << std::endl; // Output: 11
    }

    {
        /**
         * 解释: 该代码演示了C++中函数指针的用法。
         * 定义了一个函数指针`p`, 指向函数`f`, 然后调用该函数。
         * 输出结果为"Hello, World!", 表示函数`f`被成功调用。
         * 注意: 在C++中, 函数指针可以用于动态绑定和回调机制。
        **/
        void (*p)() = []() {
            std::cout << "Hello, World!" << std::endl;
        };
        p();
    }

    {
        auto f = [](char *x) {
            x++;      // 递增指针, 指向下一个字符
            *x = 'a'; // 修改指针指向的字符为'a'
        };
        // 定义一个字符数组, 并使用strcpy_s函数将字符串"hello"复制到数组中
        char str[sizeof("hello")];
        // NOLINTNEXTLINE
        // 使用strcpy_s函数将字符串"hello"复制到字符数组str中
        // 注意: strcpy_s是C++标准库中的安全字符串复制函数, 防止缓冲区溢出
        strcpy_s(str, "hello");
        // 调用函数f, 将字符数组str传递给函数
        // 函数f将修改字符数组str中的第二个字符为'a'
        f(str);
        std::cout << str;
    }

    // {
    //     // 1. 定义了一个3×2的二维数组a, 初始化所有元素为0
    //     // 2. 定义了一个指向包含2个元素数组的指针ptr
    //     // 3. 进行两次scanf输入操作：
    //     // - 第一次i=0时, ptr=a+0, 即指向第一行, 读入1
    //     // - 第二次i=1时, ptr=a+1, 即指向第二行, 读入2
    //     // - 输入的3没有被使用到, 因为循环只执行了两次

    //     // 当输入"1 2 3"时：
    //     // - 第一个数1被存入a[0][0], a[0][1]保持为0
    //     // - 第二个数2被存入a[1][0], a[1][1]保持为0
    //     // - 第三行a[2][0]和a[2][1]保持初始值0
    // int a[3][2] = {0}, (*ptr)[2], i, j;
    // for (i = 0; i < 2; i++) {
    //     ptr = a + i;
    //     scanf_s("%d", ptr);
    // }

    // for (i = 0; i < 3; i++) {
    //     for (j = 0; j < 2; j++)
    //         printf("%2d", a[i][j]);
    //     return 0;
    // }
    // }

    {
        auto f = [](int *p, int *q) {
            p++; // 递增指针p, 指向下一个整数
            *q = *q + 1;
        };

        int m = 1, n = 2, *r = &m;
        f(r, &n);
        std::cout << m << "," << n << std::endl; // 输出: 1,3
        // 解释: 函数f将指针p递增, 但没有修改m的值。
        // 同时将n的值加1, 所以最终输出m=1, n=3
    }

    {
        struct Bar {
            char c[16];
        };

        struct Test {
            Bar &bar;
        };

        std::cout << sizeof(Test) << std::endl;      // 输出: 16
        std::cout << sizeof(Test::bar) << std::endl; // 输出: 16
        // 解释: 在C++中, 引用类型的大小等于被引用对象的大小。
        // 因为Bar结构体的大小为16字节, 所以Test::bar的大小也是16字节。
        // 注意: 引用在C++中并不占用额外的内存
    }

    {
        // 1. 在main函数中定义了数组a[2]={1,2}和b[2]={10,20}，并将指针t初始化为指向数组a
        // 2. 调用fun函数时，传入三个指针参数：a、b和t
        // 3. 在fun函数中，形参t是一个指针的副本。虽然在函数内部为t分配了新的内存并赋值，但这个修改仅在函数内部有效
        // 4. 函数返回后，main函数中的指针t依然指向数组a的首地址
        // 5. 因此cout << *t输出的是a[0]的值，即1
        auto f = [](int *p1, int *p2, int *t) {
            t  = (int *) malloc(sizeof(int));
            *t = *p1 + *(p2++); //
        };

        int  a[2] = {1, 2};
        int  b[2] = {10, 20};
        int *t    = a;
        f(a, b, t);
        std::cout << *t << std::endl;
    }

    {
        // char *str = NULL;
        // str = (char *) malloc(100);
        // strcpy(str, "Thunder");
        // strcat(str + 2, "Downloader");
        // printf(str); // 输出: ThThunderDownloader
        // free(str); // 释放动态分配的内存

        char s1[] = "12345";
        char s2[] = "1234";
        // NOLINTNEXTLINE
        printf("%zu\n", strlen(strcpy(s1, s2)));
    }

    {
        char  name[] = "Tom";
        char *ptr;

        ptr = name + strlen(name);

        while (--ptr >= name) {
            puts(ptr);
        }
    }

    return 0;
}
