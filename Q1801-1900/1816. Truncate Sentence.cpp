class Solution {
public:
  string truncateSentence(string s, int k) {
    int count = 0;
    int i = 0;
    while (i < s.size() && count < k) {
      if (s[i] == ' ')
        count++;
      i++;
    }
    return s.substr(0, i - (count == k));
  }
};