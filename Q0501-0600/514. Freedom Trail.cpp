class Solution
{
public:
    int dp[101][101];
    int solve(string ring, string key, int i, int j, int n)
    {
        if (j == key.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = 0; k < n; k++)
        {
            if (ring[k] == key[j])
            {
                int temp = min(abs(k - i), n - abs(k - i)) + 1 + solve(ring, key, k, j + 1, n);
                ans = min(ans, temp);
            }
        }
        return dp[i][j] = ans;
    }
    int findRotateSteps(string ring, string key)
    {
        memset(dp, -1, sizeof(dp));
        int n = ring.size();
        return solve(ring, key, 0, 0, n);
    }
};