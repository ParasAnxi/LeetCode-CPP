using umii = unordered_map<int, int>;
using umci = unordered_map<char, int>;
using vi = vector<int>;
#define pb push_back
class Solution {
public:
  bool satisfiesConditions(vector<vector<int>> &grid) {
    int n = grid.size()
    int m = grid[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i < n - 1 && grid[i][j] != grid[i + 1][j]) {
          return 0;
        }
        if (j < m - 1 && grid[i][j] == grid[i][j + 1]) {
          return 0;
        }
      }
    }
    return 1;
  }
};