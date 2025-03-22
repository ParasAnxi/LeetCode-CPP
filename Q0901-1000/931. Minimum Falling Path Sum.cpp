class Solution{
public:
    int minFallingPathSum(vector<vector<int>> &matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for (int col = 0; col < cols; col++){
            dp[0][col] = matrix[0][col];
        }

        for (int row = 1; row < rows; row++){
            for (int col = 0; col < cols; col++){
                dp[row][col] = matrix[row][col] + min({dp[row - 1][max(col - 1, 0)],dp[row - 1][col],dp[row - 1][min(col + 1, cols - 1)]});
            }
        }
        return *min_element(dp[rows - 1].begin(), dp[rows - 1].end());
}
};