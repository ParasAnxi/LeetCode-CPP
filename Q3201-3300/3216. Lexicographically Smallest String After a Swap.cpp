class Solution {
public:
  string getSmallestString(string s) {
    for (int i = 0; i < s.size() - 1; i++) {
      char perv = s[i];
      char curr = s[i + 1];

      if (perv % 2 == curr % 2 && perv > curr) {
        s[i] = curr;
        s[i + 1] = perv;
        break;
      }
    }

    return s;
  }
};