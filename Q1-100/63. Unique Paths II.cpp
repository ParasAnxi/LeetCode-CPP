class Solution
{
public:
    int solve(vector<vector<int>> &grid, int n, int m, int i, int j, vector<vector<int>> &dp)
    {
        if (i == n - 1 && j == m - 1 && grid[i][j] == 0)
        {
            return 1;
        }
        if (i >= n || j >= m || grid[i][j] == 1)
        {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = solve(grid, n, m, i + 1, j, dp);
        int right = solve(grid, n, m, i, j + 1, dp);
        return dp[i][j] = down + right;
    }
    int tab(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long>> dp(n, vector<long>(m, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1 && grid[i][j] == 0)
                {
                    dp[i][j] = 1;
                }
                else if (i < n && j < m && grid[i][j] == 0)
                {
                    long down = (i + 1 < n) ? dp[i + 1][j] : 0;
                    long right = (j + 1 < m) ? dp[i][j + 1] : 0;
                    dp[i][j] = down + right;
                }
            }
        }
        return dp[0][0];
    }
    int so(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<long> dp(m, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (grid[i][j] == 1)
                {
                    dp[j] = 0;
                    continue;
                }
                if (i == n - 1 && j == m - 1 && grid[i][j] == 0)
                {
                    dp[j] = 1;
                }
                else if (i < n && j < m && grid[i][j] == 0)
                {
                    long down = (i + 1 < n) ? dp[j] : 0;
                    long right = (j + 1 < m) ? dp[j + 1] : 0;
                    dp[j] = down + right;
                }
            }
        }
        return dp[0];
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solve(obstacleGrid,n,m,0,0,dp);
        return so(obstacleGrid);
    }
};