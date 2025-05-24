class Solution {
public:
  int solve(int n, int lToR) {
    if (n == 1)
      return 1;
    if (lToR || n % 2 == 1) {
      return 2 * solve(n / 2, !lToR);
    } else {
      return 2 * solve(n / 2, !lToR) - 1;
    }
  }
  int lastRemaining(int n) { return solve(n, 1); }
};