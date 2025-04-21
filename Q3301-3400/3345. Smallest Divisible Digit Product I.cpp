class Solution {
public:
  int solve(int n) {
    int ans = 1;
    while (n > 0) {
      ans = ans * (n % 10);
      n = n / 10;
    }
    return ans;
  }
  int smallestNumber(int n, int t) {
    if (t == 0) return -1;
    for (int i = n; i <= 100; i++) {
      if (solve(i) % t == 0) {
        return i;
        break;
      }
    }
    return -1;
  }
};