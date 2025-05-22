class Solution {
public:
  int MOD = 1337;
  int solve(int a, int b) {
    int ans = 1;
    a %= MOD;
    while (b > 0) {
      if (b % 2 == 1) {
        ans = (ans * a) % MOD;
      }
      a = (a * a) % MOD;
      b /= 2;
    }
    return ans;
  }
  int superPow(int a, vector<int> &b) {
    int ans = 1;
    for (int i = 0; i < b.size(); i++) {
      ans = solve(ans, 10) * solve(a, b[i]) % MOD;
    }
    return ans;
  }
};