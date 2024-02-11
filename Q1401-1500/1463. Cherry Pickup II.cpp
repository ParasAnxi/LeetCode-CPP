class Solution
{
public:
    int solveMem(int i, int j1, int j2, vector<vector<int>> &grid, int rows, int cols, vector<vector<vector<int>>> &dp)
    {
        if (j1 >= cols || j1 < 0 || j2 >= cols || j2 < 0)
        {
            return 0;
        }

        if (i == rows - 1)
        {
            if (j1 == j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1] + grid[i][j2];
            }
        }

        if (dp[i][j1][j2] != -1)
        {
            return dp[i][j1][j2];
        }
        int maxi = INT_MIN;
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                if (j1 == j2)
                {
                    maxi = max(maxi, grid[i][j1] + solveMem(i + 1, j1 + dj1, j2 + dj2, grid, rows, cols, dp));
                }
                else
                {
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + solveMem(i + 1, j1 + dj1, j2 + dj2, grid, rows, cols, dp));
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int solveTab(vector<vector<int>> &grid, int n, int cols)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(cols, vector<int>(cols, 0)));
        for (int j1 = 0; j1 < cols; j1++)
        {
            for (int j2 = 0; j2 < cols; j2++)
            {
                if (j1 == j2)
                {
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                }
                else
                {
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
                }
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < cols; j1++)
            {
                for (int j2 = 0; j2 < cols; j2++)
                {
                    int maxi = -1e8;
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int value = 0;
                            if (j1 == j2)
                            {
                                value = grid[i][j1];
                            }
                            else
                            {
                                value = grid[i][j1] + grid[i][j2];
                            }

                            if (j1 + dj1 >= 0 && j1 + dj1 < cols && j2 + dj2 >= 0 && j2 + dj2 < cols)
                            {
                                value += dp[i + 1][j1 + dj1][j2 + dj2];
                            }
                            else
                            {
                                value += -1e8;
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][cols - 1];
    }
    int solveSo(vector<vector<int>> &grid, int n, int cols)
    {
        vector<vector<int>> curr(cols, vector<int>(cols, 0));
        vector<vector<int>> next(cols, vector<int>(cols, 0));
        for (int j1 = 0; j1 < cols; j1++)
        {
            for (int j2 = 0; j2 < cols; j2++)
            {
                if (j1 == j2)
                {
                    next[j1][j2] = grid[n - 1][j1];
                }
                else
                {
                    next[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
                }
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < cols; j1++)
            {
                for (int j2 = 0; j2 < cols; j2++)
                {
                    int maxi = -1e8;
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int value = 0;
                            if (j1 == j2)
                            {
                                value = grid[i][j1];
                            }
                            else
                            {
                                value = grid[i][j1] + grid[i][j2];
                            }

                            if (j1 + dj1 >= 0 && j1 + dj1 < cols && j2 + dj2 >= 0 && j2 + dj2 < cols)
                            {
                                value += next[j1 + dj1][j2 + dj2];
                            }
                            else
                            {
                                value += -1e8;
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            next = curr;
        }
        return curr[0][cols - 1];
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        // return solveMem(0,0,m-1,grid,n,m,dp);
        // return solveTab(grid,n,m);
        return solveSo(grid, n, m);
    }
};