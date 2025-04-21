class Solution {
public:
  int minimumChairs(string s) {
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'E') cnt++;
      if (cnt > ans) ans = cnt;
      if (s[i] == 'L') cnt--;
    }
    return ans;
  }
};