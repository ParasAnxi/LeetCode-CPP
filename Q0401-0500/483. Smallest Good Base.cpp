class Solution {
public:
  long long solveB(int n, long long bs, long long tar) {
    long long ans = 0;
    int oneC = 0;
    for (int i = 0; i < n && ans <= (tar - 1) / bs; i++) {
      ans *= bs;
      ans++;
      oneC++;
    }
    if (oneC < n)
      return LLONG_MAX;
    return ans;
  }

  long long solveK(long long n, int i) {
    long long s = 1, e = n - 1;
    while (s + 1 < e) {
      long long mid = (s + e) / 2;
      if (n <= solveB(i, mid, n))
        e = mid;
      else
        s = mid;
    }
    if (solveB(i, e, n) == n)
      return e;
    return -1;
  }
  string smallestGoodBase(string n) {
    long long nN = stoll(n);
    for (int i = 64; i >= 2; i--) {
      long long base = solveK(nN, i);
      if (base != -1)
        return to_string(base);
    }
    return "";
  }
};