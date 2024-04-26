class Solution
{
public:
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (row == 0)
        {
            return grid[row][col];
        }

        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        int ans = 1e9;
        for (int i = 0; i < grid.size(); i++)
        {
            if (i == col)
                continue;
            ans = min(ans, grid[row][col] + solve(row - 1, i, grid, dp));
        }
        return dp[row][col] = ans;
    }
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {
            ans = min(ans, solve(n - 1, i, grid, dp));
        }
        return ans;
    }
};