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
  vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    int o = min(m, n) / 2;
    for (int i = 0; i < o; i++) {
      vi vI;
      int r1 = i;
      int r2 = m - 1 - i;
      int c1 = i;
      int c2 = n - 1 - i;
      for (int j = c1; j <= c2; j++) {
        vI.pb(grid[r1][j]);
      }
      for (int i = r1 + 1; i <= r2; i++) {
        vI.pb(grid[i][c2]);
      }
      for (int j = c2 - 1; j >= c1; j--) {
        vI.pb(grid[r2][j]);
      }
      for (int i = r2 - 1; i > r1; i--) {
        vI.pb(grid[i][c1]);
      }
      int n = vI.size();
      int shift = k % n;
      vi vR(n);
      for (int i = 0; i < n; i++) {
        vR[i] = vI[(i + shift) % n];
      }
      int idx = 0;
      for (int j = c1; j <= c2; j++) {
        grid[r1][j] = vR[idx++];
      }
      for (int i = r1 + 1; i <= r2; i++) {
        grid[i][c2] = vR[idx++];
      }
      for (int j = c2 - 1; j >= c1; j--) {
        grid[r2][j] = vR[idx++];
      }
      for (int i = r2 - 1; i > r1; i--) {
        grid[i][c1] = vR[idx++];
      }
    }
    return grid;
  }
};
