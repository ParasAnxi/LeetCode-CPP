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
  int minOperations(vector<vector<int>> &grid, int x) {
    int m = grid.size();
    int n = grid[0].size();
    int r = grid[0][0] % x;
    vi vI(m * n, 0);
    int count = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] % x != r) {
          return -1;
          break;
        }
        vI[count] = grid[i][j];
        count++;
      }
    }
    sort(vI.begin(), vI.end());
    int ans = INT_MAX;
    if (m * n % 2 == 0) {
      int op = 0;
      for (int i = 0; i < m * n; i++) {
        op += abs(vI[i] - vI[m * n / 2]) / x;
      }
      ans = min(ans, op);
      op = 0;
      for (int i = 0; i < m * n; i++) {
        op += abs(vI[i] - vI[(m * n - 2) / 2]) / x;
      }
      ans = min(ans, op);
    } else {
      int op = 0;
      for (int i = 0; i < m * n; i++) {
        op += abs(vI[i] - vI[(m * n - 1) / 2]) / x;
      }
      ans = min(ans, op);
    }
    return ans;
  }
};