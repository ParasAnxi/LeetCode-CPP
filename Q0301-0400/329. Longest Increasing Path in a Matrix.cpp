class Solution {
public:
  int solve(int i, int j, vector<vector<int>> &matrix, int n, int m,
            vector<vector<int>> &dp) {
    if (!(i >= 0 && i < n && j >= 0 && j < m))
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    int ans = 1;
    if (j + 1 < m && matrix[i][j + 1] > matrix[i][j])
      ans = max(ans, 1 + solve(i, j + 1, matrix, n, m, dp));
    if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
      ans = max(ans, 1 + solve(i, j - 1, matrix, n, m, dp));
    if (i + 1 < n && matrix[i + 1][j] > matrix[i][j])
      ans = max(ans, 1 + solve(i + 1, j, matrix, n, m, dp));
    if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
      ans = max(ans, 1 + solve(i - 1, j, matrix, n, m, dp));
    return dp[i][j] = ans;
  }
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = INT_MIN;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i][j] = solve(i, j, matrix, n, m, dp);
        ans = max(ans, dp[i][j]);
      }
    }
    return ans;
  }
};