/**
 *
**/


#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
  public:
    int minArray(std::vector<int> &numbers) {


        int result = numbers[0];

        for (int i: numbers) {
            if (result > i) {
                result = i;
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    (void) argc;
    (void) argv;
    return 0;
}