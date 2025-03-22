class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(int depth, int l, int a, int &n, vector<vector<vector<int>>> &dp)
    {
        if (l >= 3)
        {
            return 0;
        }
        if (a >= 2)
        {
            return 0;
        }
        if (depth >= n)
            return 1;

        if (dp[depth][l][a] != -1)
            return dp[depth][l][a];

        int present = solve(depth + 1, 0, a, n, dp);
        int late = solve(depth + 1, l + 1, a, n, dp);
        int absent = solve(depth + 1, 0, a + 1, n, dp);

        return dp[depth][l][a] = ((present + late) % mod + absent) % mod;
    }

    int checkRecord(int n)
    {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2, -1)));
        int ans = solve(0, 0, 0, n, dp);
        return ans;
    }
};