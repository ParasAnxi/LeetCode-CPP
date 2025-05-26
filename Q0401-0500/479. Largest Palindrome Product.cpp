class Solution {
public:
  long solve(int num) {
    string nStr = to_string(num);
    string rev = nStr;
    reverse(rev.begin(), rev.end());
    return stol(nStr + rev);
  }
  int largestPalindrome(int n) {
    if (n == 1)
      return 9;
    int maxi = pow(10, n) - 1;
    int mini = pow(10, n - 1);

    for (int i = maxi; i >= mini; i--) {
      long pali = solve(i);
      for (long j = maxi; j * j >= pali; j--) {
        if (pali % j == 0 && pali / j <= maxi) {
          return pali % 1337;
        }
      }
    }
    return -1;
  }
};