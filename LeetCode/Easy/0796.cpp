class Solution {
  public:
    bool rotateString(string s, string goal) {
        return s.size() != goal.size() ? false : (s + s).find(goal) != -1;
    }
};