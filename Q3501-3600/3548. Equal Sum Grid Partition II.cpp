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
  bool canPartitionGrid(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    ll sum = 0;
    int vE[100001] = {};
    int vCe[100001] = {};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        sum += grid[i][j];
        vE[grid[i][j]]++;
      }
    }
    ll curr = 0;
    for (int j = 0; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        curr += grid[i][j];
        vCe[grid[i][j]]++;
        vE[grid[i][j]]--;
      }
      if (j == m - 1)
        break;
      if (curr == sum - curr)
        return true;
      ll right = sum - curr;
      ll diff = right - curr;
      if (abs(diff) > 100000)
        continue;
      if (diff > 0) {
        if (n == 1) {
          if (diff == grid[0][j])
            return true;
          if (diff == grid[0][m - 1] || diff == grid[n - 1][m - 1])
            return true;
          continue;
        } else if (j != m - 2 && vE[diff] > 0)
          return true;
        if (j == m - 2) {
          if (diff == grid[0][m - 1] || diff == grid[n - 1][m - 1])
            return true;
        }
      } else if (diff < 0) {
        if (n == 1) {
          if (-diff == grid[0][j])
            return true;
          if (-diff == grid[0][0] || -diff == grid[n - 1][0])
            return true;
          continue;
        } else if (j != 0 && vCe[-diff] > 0)
          return true;
        if (j == 0) {
          if (-diff == grid[0][0] || -diff == grid[n - 1][0])
            return true;
        }
      }
    }
    for (int i = 0; i <= 100000; ++i) {
      vE[i] = vCe[i];
      vCe[i] = 0;
    }
    curr = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        curr += grid[i][j];
        vCe[grid[i][j]]++;
        vE[grid[i][j]]--;
      }
      if (i == n - 1)
        break;
      if (curr == sum - curr)
        return true;
      ll bottom = sum - curr;
      ll diff = bottom - curr;
      if (abs(diff) > 100000)
        continue;
      if (diff > 0) {
        if (m == 1) {
          if (diff == grid[i][0])
            return true;
          if (diff == grid[n - 1][0] || diff == grid[n - 1][m - 1])
            return true;
          continue;
        } else if (m != 1 && i != n - 2 && vE[diff] > 0)
          return true;
        if (i == n - 2) {
          if (diff == grid[n - 1][0] || diff == grid[n - 1][m - 1])
            return true;
        }
      } else if (diff < 0) {
        if (m == 1) {
          if (-diff == grid[i][0])
            return true;
          if (-diff == grid[0][0] || -diff == grid[0][m - 1])
            return true;
          continue;
        } else if (m != 1 && i != 0 && vCe[-diff] > 0)
          return true;
        if (i == 0) {
          if (-diff == grid[0][0] || -diff == grid[0][m - 1])
            return true;
        }
      }
    }
    return false;
  }
};