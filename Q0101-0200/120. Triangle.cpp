class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
      dp[i][0] = triangle[i][0] + dp[i - 1][0];
      for (int j = 1; j <= i; j++) {
        dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
      }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
  }
};