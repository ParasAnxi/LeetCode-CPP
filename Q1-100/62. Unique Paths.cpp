class Solution
{
public:
    int solve(int m, int n, int i, int j, vector<vector<int>> &dp)
    {
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = 0;
        int right = 0;
        if (i + 1 < m)
            down = solve(m, n, i + 1, j, dp);
        if (j + 1 < n)
            right = solve(m, n, i, j + 1, dp);
        return dp[i][j] = down + right;
    }
    int tab(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                {
                    continue;
                }
                int down = 0;
                int right = 0;
                if (i + 1 < m)
                    down = dp[i + 1][j];
                if (j + 1 < n)
                    right = dp[i][j + 1];
                dp[i][j] = down + right;
            }
        }
        return dp[0][0];
    }
    int so(int m, int n)
    {
        vector<int> dp(n, 0);
        dp[n - 1] = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                {
                    continue;
                }
                int down = 0;
                int right = 0;
                if (i + 1 < m)
                    down = dp[j];
                if (j + 1 < n)
                    right = dp[j + 1];
                dp[j] = down + right;
            }
        }
        return dp[0];
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(m,n,0,0,dp);
        return so(m, n);
    }
};