class Solution {
public:
  int numberOfChild(int n, int k) {
    int x = 0;
    int ans = 0;
    for (int i = 0; i < k; i++) {
      if (x == 0) {
        ans++;
        if (ans == n - 1) {
          x = 1;
        }

      } else if (x == 1) {
        ans--;
        if (ans == 0) {
          x = 0;
        }
      }
    }
    return ans;
  }
};