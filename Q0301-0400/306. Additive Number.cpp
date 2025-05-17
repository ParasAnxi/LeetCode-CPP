class Solution {
public:
  bool solve(int ans, long long b, long long i, string num) {
    int n = num.size();
    if (i == n)
      return 1;
    bool ans = 0;

    for (int j = i; j < n && j - i <= n / 2; j++) {
      long long k = stoll(num.substr(i, j - i + 1));
      if (num[i] != '0' || j < i + 1)
        if (k == ans + b)
          ans |= solve(b, k, j + 1, num);
    }

    return ans;
  }
  bool isAdditiveNumber(string num) {
    int n = num.size();
    if (n < 3)
      return 0;
    for (int i = 0; i < n / 2; i++) {
      if (num[0] != '0' || i < 1)
        for (int j = i + 1; j < n - 1 && j - i <= n / 2; j++)
          if (num[i + 1] != '0' || j - i - 1 < 1) {
            bool ans = solve(stoll(num.substr(0, i + 1)),
                             stoll(num.substr(i + 1, j - i)), j + 1, num);
            if (ans == 1)
              return 1;
          }
    }

    return 0;
  }
};