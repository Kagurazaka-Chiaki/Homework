/**
 * @file TX01.cpp
 *
 * 给定一个数组， 数组里只有 0, 1,
 * 并符合规则 "1 和 1 之间至少间隔 1 个 0"
 * 在不破坏规则的情况下，尽可能多的将 0 替换成 1
 *
 * Input  : [1, 0, 0, 0, 1]
 * Output : [1, 0, 1, 0, 1]
 *
 * Input  : [0, 1, 0, 0, 0]
 * Output : [0, 1, 0, 1, 0]
 *
 **/

#include <algorithm>
#include <bits/stdc++.h>
#include <memory>
#include <vector>

#include <Eigen/Dense>

using namespace std;

// auto calc(vector<int> const &input) -> vector<int> {
//   vector<int> result;

//   return result;
// }

// struct vertex {
//   std::unique_ptr<int> data;

//   vertex(int const &data) { this->data = std::make_unique<int>(data); };

//   auto operator*() -> int { return *data; }

//   auto operator<(vertex const &other) const -> bool {
//     return *data < *(other.data);
//   }
// };

// auto main(int argc, char const *argv[]) -> int {
//     (void) argc; (void) argv;
//     /* code */
//     std::cout << "Hello, World! \xF0\x9F\x98\x89 \n" << std::endl;

//     std::map<vertex, int> m;

//     auto v = vertex(20);

//     m[v] = 20;

//     return 0;
// }

// struct Info {
//   string name;
//   int score;

//   bool operator<(const Info &x) const { return score < x.score; }
// };

// int main()
// {
//     Info a, b;
//     a.name = "eric";
//     a.score = 90;
//     b.name = "cat";
//     b.score = 85;
//     std::map<vertex, int> m2;
//     auto v = vertex(20);
//     m2[v] = 20;
//     map<Info, int> m;
//     m[a] = 1;
//     m[b] = 2;
//     map<Info, int>::iterator it;
//     for(it = m.begin(); it != m.end(); it++)
//     {
//         cout << it->first.name << endl;
//     }
//     return 0;
// }

// struct Comparator {
//   bool operator()(shared_ptr<string> const &left, shared_ptr<string> const &right) const {
//     return left->compare(*right) < 0;
//         // The comparer should return whether the first string should go
//         // before the second string. Either return x.compare(y) < 0
//   }
// };

// int main() {
//     map<shared_ptr<string>, int, Comparator> test;
//     test.insert(make_pair(make_shared<string>("test1"), 123));
//     test.insert(make_pair(make_shared<string>("test2"), 234));
//     test.insert(make_pair(make_shared<string>("test3"), 369));
//     test.insert(make_pair(make_shared<string>("test4"), 258));
//     // test.insert(make_pair(make_shared<string>("test4"),99));

//     //  cout<<"test:"<<test[make_shared<string>("test5")]<<endl;//carefull
//     cout << "size:" << test.size() << endl;
//     shared_ptr<string> key = make_shared<string>("test4");
//     int count = test.count(key);
//     if (count == 1) {
//         map<shared_ptr<string>, int, Comparator>::iterator it = test.find(key);
//         cout << "value:" << it->second << endl;
//     }

//     return 0;
// }