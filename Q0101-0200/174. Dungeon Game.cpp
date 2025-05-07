class Solution {
public:
  int solve(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp) {
    int n = arr.size();
    int m = arr[0].size();
    if (i >= n || j >= m)
      return 1e9;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (i == n - 1 and j == m - 1) {
      return dp[i][j] = max(1, 1 - arr[i][j]);
    }
    int right = solve(i, j + 1, arr, dp);
    int down = solve(i + 1, j, arr, dp);
    int cellEff = arr[i][j];
    int mini = min(right, down);
    return dp[i][j] = max(1, mini - cellEff);
  }
  int solveTab(vector<vector<int>> &dungeon) {
    int n = dungeon.size();
    int m = dungeon[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (i == n - 1 and j == m - 1)
          dp[i][j] = max(1, 1 - dungeon[n - 1][m - 1]);
        else {
          int right = 1e9, down = 1e9;
          if (j + 1 < m)
            right = min(right, dp[i][j + 1]);
          if (i + 1 < n)
            down = min(down, dp[i + 1][j]);
          int mini = min(right, down);
          dp[i][j] = max(1, mini - dungeon[i][j]);
        }
      }
    }
    return dp[0][0];
  }
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int n = dungeon.size();
    int m = dungeon[0].size();
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return solve(0, 0, dungeon, dp);
    return solveTab(dungeon);
  }
};