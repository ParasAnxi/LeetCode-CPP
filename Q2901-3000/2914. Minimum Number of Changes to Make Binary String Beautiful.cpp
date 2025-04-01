class Solution {
public:
  int minChanges(string s) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i += 2) {
      int e = 0;
      e += s[i] - '0';
      e += s[i + 1] - '0';

      ans += (e % 2);
    }
    return ans;
  }
};