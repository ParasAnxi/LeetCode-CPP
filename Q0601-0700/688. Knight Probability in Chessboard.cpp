class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
    {
        double dp[n + 1][n + 1][k + 1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j][0] = 1;
            }
        }
        for (int a = 1; a <= k; a++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dp[i][j][a] = 0;
                    if ((i + 1 < n) && (j + 2 < n))
                    {
                        dp[i][j][a] += (dp[i + 1][j + 2][a - 1]);
                    }
                    if ((i + 1) < n && (j - 2) >= 0)
                    {
                        dp[i][j][a] += (dp[i + 1][j - 2][a - 1]);
                    }
                    if ((j + 1 < n) && (i + 2 < n))
                    {
                        dp[i][j][a] += (dp[i + 2][j + 1][a - 1]);
                    }
                    if ((j + 1) < n && (i - 2) >= 0)
                    {
                        dp[i][j][a] += (dp[i - 2][j + 1][a - 1]);
                    }
                    if ((i - 1 >= 0) && (j + 2 < n))
                    {
                        dp[i][j][a] += (dp[i - 1][j + 2][a - 1]);
                    }
                    if ((i - 1) >= 0 && (j - 2) >= 0)
                    {
                        dp[i][j][a] += (dp[i - 1][j - 2][a - 1]);
                    }
                    if ((j - 1 >= 0) && (i + 2 < n))
                    {
                        dp[i][j][a] += (dp[i + 2][j - 1][a - 1]);
                    }
                    if ((j - 1) >= 0 && (i - 2) >= 0)
                    {
                        dp[i][j][a] += (dp[i - 2][j - 1][a - 1]);
                    }
                    dp[i][j][a] /= 8;
                }
            }
        }
        return dp[row][column][k];
    }
};