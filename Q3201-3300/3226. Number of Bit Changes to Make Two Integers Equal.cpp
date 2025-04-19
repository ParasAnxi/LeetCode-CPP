class Solution {
public:
  int minChanges(int n, int k) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
      int x = (n >> i) & 1;
      int y = (k >> i) & 1;
      if (!x && y) return -1;
      ans += x ^ y;
    }
    return ans;
  }
};