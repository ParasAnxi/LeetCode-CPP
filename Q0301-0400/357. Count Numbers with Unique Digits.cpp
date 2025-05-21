class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0)
      return 1;
    if (n == 1)
      return 10;
    int ans = 10;
    int x = 9, y = 9;
    for (int i = 2; i <= n; i++) {
      x = x * y;
      ans = ans + x;
      y--;
    }
    return ans;
  }
};