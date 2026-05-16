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
  int n, m;
  int solve(int i, int j, int xr, vvi &grid, vvvi &dp) {
    if (i >= n || j >= m) {
      return INT_MAX;
    }
    xr = xr ^ grid[i][j];
    if (i == n - 1 && j == m - 1) {
      return xr;
    }
    if (dp[i][j][xr] != -1) {
      return dp[i][j][xr];
    }
    int right = solve(i, j + 1, xr, grid, dp);
    int down = solve(i + 1, j, xr, grid, dp);
    return dp[i][j][xr] = min(right, down);
  }

  int minCost(vector<vector<int>> &grid) {
    n = grid.size();
    m = grid[0].size();
    vvvi dp(n, vvi(m, vi(1024, -1)));
    return solve(0, 0, 0, grid, dp);
  }
};