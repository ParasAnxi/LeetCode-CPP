class Solution {
public:
  int countDigitOne(int n) {
    long long count = 0;
    for (long long i = 1; i <= n; i *= 10) {
      long long h = n / (i * 10);
      long long curr = (n / i) % 10;
      long long l = n % i;
      if (curr == 0)
        count += h * i;
      else if (curr == 1)
        count += h * i + l + 1;
      else
        count += (h + 1) * i;
    }
    return (int)count;
  }
};