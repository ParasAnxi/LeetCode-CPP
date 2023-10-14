class Solution
{
public:
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        int n = cost.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2 * n + 1, 0));
        for (int j = 0; j <= (2 * n); j++)
            dp[n][j] = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                long long pick = INT_MAX;
                if (j - (time[i] + 1) <= 0)
                    pick = cost[i];
                else
                    pick = cost[i] + dp[i + 1][j - (time[i] + 1)];
                long long notpick = dp[i + 1][j];
                dp[i][j] = min(pick, notpick);
            }
        }
        return (int)dp[0][n];
    }
};