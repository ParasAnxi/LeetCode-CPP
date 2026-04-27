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
  void solve(int row, int col, vvi &grid, unordered_map<int, vpii> &mp,
             vvi &vis, int n, int m, bool &ans) {
    vis[row][col] = 1;
    if (row == n - 1 && col == m - 1)
      ans = 1;
    for (auto i : mp[grid[row][col]]) {
      int nR = row + i.first;
      int nC = col + i.second;
      bool cG = 0;
      if (nR >= 0 && nR < n && nC < m && nC >= 0 && !vis[nR][nC]) {
        for (auto par : mp[grid[nR][nC]]) {
          int pR = nR + par.first;
          int pC = nC + par.second;
          if (pR == row && pC == col) {
            cG = 1;
          }
        }
        if (cG)
          solve(nR, nC, grid, mp, vis, n, m, ans);
      }
    }
    vis[row][col] = 0;
  }
  bool hasValidPath(vector<vector<int>> &grid) {
    bool ans = 0;
    int n = grid.size();
    int m = grid[0].size();
    vvi vis(n, vi(m, 0));
    unordered_map<int, vpii> mp;
    mp[1] = {{0, -1}, {0, 1}};
    mp[2] = {{1, 0}, {-1, 0}};
    mp[3] = {{0, -1}, {1, 0}};
    mp[4] = {{0, 1}, {1, 0}};
    mp[5] = {{0, -1}, {-1, 0}};
    mp[6] = {{0, 1}, {-1, 0}};
    solve(0, 0, grid, mp, vis, n, m, ans);
    return ans;
  }
};