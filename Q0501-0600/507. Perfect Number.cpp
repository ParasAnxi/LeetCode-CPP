class Solution {
public:
  bool checkPerfectNumber(int n) {
    int i = 0;
    int sum = 0;
    for (i = 1; i < n; i++) {
      if (n % i == 0)
        sum = sum + i;
    }
    return (sum == n);
  }
};