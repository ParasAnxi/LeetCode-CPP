using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ppii = pair<int, pii>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vc = vector<char>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using pis = pair<int, string>;
using vs = vector<string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using umii = unordered_map<int, int>;
using umci = unordered_map<char, int>;
#define pb push_back
#define MOD 1000000007
#define LMOD 1000000000000000007LL
class Solution {
public:
#define ll long long
  ll dp[101][102][2];
  int n;
  ll solve(int c, int pM, int cov, vector<vll> &vP) {
    if (c >= n)
      return 0;
    if (dp[c][pM + 1][cov] != -1)
      return dp[c][pM + 1][cov];
    ll ans = 0;
    for (int r = -1; r < n; r++) {
      ll curr = (r <= pM) ? vP[c + 1][pM + 1] - vP[c + 1][r + 1] : 0;
      ll prev = (r > pM && cov == 0) ? vP[c][r + 1] - vP[c][pM + 1] : 0;
      ll r1 = curr + prev + solve(c + 1, r, 1, vP);
      ll r2 = prev + solve(c + 1, r, 0, vP);
      ans = max(ans, max(r1, r2));
    }
    return dp[c][pM + 1][cov] = ans;
  }
  long long maximumScore(vector<vector<int>> &grid) {
    n = grid.size();
    memset(dp, -1, sizeof(dp));
    vector<vll> vP(n + 1, vll(n + 1, 0));
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        vP[j + 1][i + 1] = vP[j + 1][i] + grid[i][j];
      }
    }
    return solve(0, -1, 0, vP);
  }
};