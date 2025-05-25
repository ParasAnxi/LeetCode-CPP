class Solution {
public:
  int integerReplacement(int x) {
    long long n = x;
    int ans = 0;
    while (n > 1) {
      if (n % 2 == 0) {
        n /= 2;
      } else {
        if (n == 3 || (n & 2) == 0) {
          n -= 1;
        } else {
          n += 1;
        }
      }
      ans++;
    }
    return ans;
  }
};