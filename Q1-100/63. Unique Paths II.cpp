class Solution
{
public:
    int solveMem(vector<vector<int>> &grid, int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        if (i == n - 1 && j == m - 1 && grid[i][j] == 0)
            return 1;
        if (i >= n || j >= m || grid[i][j] == 1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = solveMem(grid, i + 1, j, n, m, dp);
        int right = solveMem(grid, i, j + 1, n, m, dp);

        dp[i][j] = down + right;

        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solveMem(obstacleGrid, 0, 0, n, m, dp);
    }
};