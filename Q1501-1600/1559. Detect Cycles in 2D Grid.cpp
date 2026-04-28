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
  bool solve(vector<vector<char>> &grid, int n, int m, int i, int j, vvi &vis,
             int pI, int pJ) {
    if (i < 0 || i >= n || j < 0 || j >= m)
      return 0;
    if (pI != -1 && pJ != -1 && grid[i][j] != grid[pI][pJ])
      return 0;
    if (vis[i][j])
      return 1;
    vis[i][j] = 1;
    if (i - 1 >= 0 && i - 1 != pI)
      if (solve(grid, n, m, i - 1, j, vis, i, j))
        return 1;
    if (i + 1 < n && i + 1 != pI)
      if (solve(grid, n, m, i + 1, j, vis, i, j))
        return 1;
    if (j - 1 >= 0 && j - 1 != pJ)
      if (solve(grid, n, m, i, j - 1, vis, i, j))
        return 1;
    if (j + 1 < m && j + 1 != pJ)
      if (solve(grid, n, m, i, j + 1, vis, i, j))
        return 1;
    return 0;
  }
  bool containsCycle(vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vvi vis(n, vi(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j]) {
          if (solve(grid, n, m, i, j, vis, -1, -1))
            return 1;
        }
      }
    }

    return 0;
  }
};