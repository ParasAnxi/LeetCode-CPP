using ll = long long;
using ull = unsigned long long;
using ld = long double;
using cd = complex<double>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using pll = pair<ll, ll>;
using pci = pair<char, int>;
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
  bool isPossilbe(int i, int j,int n, int m) { 
    return !(i >= n || j >= m); 
  }
  bool check(int i, int j, vvi &grid) {
    return grid[i][j] != 0;
  }
  ll solve(int n, int m, vvi &grid, int i, int j, int k,vvvi &dp) {
    if (!isPossilbe(i, j, n, m) || check(i, j, grid) > k){
      return -1e9;
    }
    if (i == n - 1 && j == m - 1){
      return grid[i][j];
    }
    if (dp[i][j][k] != -1e4){
      return dp[i][j][k];
    }
    int cost = check(i, j, grid);
    int down = solve(n, m, grid, i + 1, j, k - cost, dp);
    int right = solve(n, m, grid, i, j + 1, k - cost, dp);
    return dp[i][j][k] = grid[i][j] + max(down, right);
  }
  int solveTab(vector<vector<int>> &grid, int k) {
    int n = grid.size(), m = grid[0].size();
    vvvi dp(n, vvi(m, vi(k + 1, -1e4)));
    dp[0][0][grid[0][0] != 0] = grid[0][0];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int l = 0; l <= k; l++) {
          int cost = (grid[i][j] != 0);
          if (i > 0) {
            if (l - cost >= 0)
              dp[i][j][l] = max(dp[i][j][l], grid[i][j] + dp[i - 1][j][l - cost]);
          }
          if (j > 0) {
            if (l - cost >= 0)
              dp[i][j][l] = max(dp[i][j][l], grid[i][j] + dp[i][j - 1][l - cost]);
          }
        }
      }
    }
    int ans = INT_MIN;
    for (int i = 0; i <= k; i++) {
      ans = max(ans, dp[n - 1][m - 1][i]);
    }
    return ans < 0 ? -1 : ans;
  }
  int maxPathScore(vector<vector<int>> &grid, int k) {
    // int n = grid.size(), m = grid[0].size();
    // vvvi dp(n, vvi(m, vi(k + 1, -1e4)));
    // int ans = solve(n, m, grid, 0, 0, k, dp);
    // return ans < 0 ? -1 : ans;
    return solveTab(grid, k);
  }
};