class Solution {
public:
  bool hasSpecialSubstring(string s, int k) {
    int n = s.length();
    int i = 0;
    for (int j = 0; j < n; j++) {
      if (s[i] == s[j]) continue;
      if (j - i == k) return 1;
      i = j;
    }
    return (n - i) == k;
  }
};