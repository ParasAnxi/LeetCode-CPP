using ll = long long;
using ull = unsigned long long;
using ld = long double;
using cd = complex<double>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using pll = pair<ll, ll>;
using ppii = pair<int, pii>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using pis = pair<int, string>;
using vs = vector<string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using pli = pair<ll, int>;
using umii = unordered_map<int, int>;
using umcvi = unordered_map<char, vi>;
using umsi = unordered_map<string, int>;
using mivi = map<int, vi>;
using umci = unordered_map<char, int>;
#define pb push_back
#define MOD 1000000007
#define LMOD 1000000000000000007LL
class Solution {
public:
  vector<vvi> dp;
  int m, n;
  int solve(int i, int j, int pwr, vvi &coins) {
    if (i == m - 1 && j == n - 1) {
      if (coins[i][j] >= 0 || pwr == 0) {
        return coins[i][j];
      }
      return 0;
    }
    if (dp[i][j][pwr] != INT_MIN) {
      return dp[i][j][pwr];
    }
    int ans = INT_MIN;
    if (i + 1 < m) {
      ans = max(ans, coins[i][j] + solve(i + 1, j, pwr, coins));
      if (coins[i][j] < 0 && pwr > 0) {
        ans = max(ans, solve(i + 1, j, pwr - 1, coins));
      }
    }
    if (j + 1 < n) {
      ans = max(ans, coins[i][j] + solve(i, j + 1, pwr, coins));
      if (coins[i][j] < 0 && pwr > 0) {
        ans = max(ans, solve(i, j + 1, pwr - 1, coins));
      }
    }
    return dp[i][j][pwr] = ans;
  }
  int maximumAmount(vector<vector<int>> &coins) {
    m = coins.size(), n = coins[0].size();
    dp.resize(m, vvi(n, vi(3, INT_MIN)));
    return solve(0, 0, 2, coins);
  }
};