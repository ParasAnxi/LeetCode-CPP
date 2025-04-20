class Solution {
public:
  int minimumOperations(vector<vector<int>> &grid) {
    int ans = 0;
    for (int i = 0; i < grid[0].size(); i++) {
      for (int j = 1; j <= grid.size() - 1; j++) {
        if (grid[j - 1][i] >= grid[j][i]) {
          int cnt = 0;
          while (((grid[j - 1][i]) + 1) != ((grid[j][i]) + cnt)) {
            cnt++;
          }
          ans = ans + cnt;
          grid[j][i] = grid[j][i] + cnt;
        }
      }
    }
    return ans;
  }
};