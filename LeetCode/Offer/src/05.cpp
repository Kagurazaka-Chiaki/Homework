#include <iostream>

#include <string>

std::string replaceSpace(std::string s) {
    int count = 0;
    int length = s.length();

    for (char c : s) {
        if (c == ' ') { count++; }
    }

    int new_length = count * 2 + length;

    s.resize(new_length);

    int j = length;
    for (int i = new_length; i > -1; i--) {
        if (s[j] == ' ') {
            j--;
            s[i--] = '0';
            s[i--] = '2';
            s[i] = '%';
        } else {
            s[i] = s[j--];
        }
    }

    return s;
}

int main(int argc, char const *argv[]) {
    /* code */

    std::cout << replaceSpace("We are happy.") << std::endl;

    return 0;
}

// [17 \0] -> [13 \0]
// [16 \0] -> [12  .]
// [15 \0] -> [11  y]
// [14 \0] -> [10  p]
// [13 \0] -> [ 9  p]
// [12  .] -> [ 8  a]
// [11  y] -> [ 7  h]
// [10  p] -> [ 6   ]
// [ 7  h] -> [ 5  e]
// [ 6   ] -> [ 4  r]
// [ 5  e] -> [ 3  a]
// [ 4  r] -> [ 2   ]
// [ 1  e] -> [ 1  e]
// [ 0  W] -> [ 0  W]
//
// We%20are%20happy.