/**
 * @brief 455. 分发饼干
 * 
 * https://leetcode-cn.com/problems/assign-cookies/
 * 
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = g.size() - 1, j = s.size() - 1;
        int result = 0;
        while (i >= 0 && j >= 0) {
            if (s[j] >= g[i]) {
                --i, --j;
                result++;
            } else
                i--;
        }
        return result;
    }
};

int cmp(void const *a, void const *b) {
    return *(int *) a - *(int *) b;
}

int findContentChildren(int *g, int gSize, int *s, int sSize) {
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int i = gSize - 1, j = sSize - 1;
    int result = 0;
    while (i >= 0 && j >= 0) {
        if (s[j] >= g[i]) {
            --i, --j;
            result++;
        } else
            i--;
    }
    return result;
}