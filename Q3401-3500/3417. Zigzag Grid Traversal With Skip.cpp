using vi = vector<int>;
#define pb push_back
class Solution {
public:
  vector<int> zigzagTraversal(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vi v;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        for (int j = 0; j < m; j++) {
          v.pb(grid[i][j]);
        }
      } else {
        for (int j = m - 1; j >= 0; j--) {
          v.pb(grid[i][j]);
        }
      }
    }
    vi ans;
    for (int i = 0; i < v.size(); i += 2) {
      ans.pb(v[i]);
    }
    return ans;
  }
};