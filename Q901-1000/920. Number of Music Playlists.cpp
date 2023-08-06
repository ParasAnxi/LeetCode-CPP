class Solution
{
public:
    int mod = 1e9 + 7;
#define ll long long
    ll f(int ind, int tar, int k, vector<vector<int>> &dp)
    {
        if (ind == 0 && tar == 0)
            return 1;
        if (ind == 0 || tar == 0)
            return 0;
        if (dp[ind][tar] != -1)
            return dp[ind][tar];

        ll pick = f(ind - 1, tar - 1, k, dp) * ind;
        ll nPick = f(ind, tar - 1, k, dp) * max(ind - k, 0);

        return dp[ind][tar] = (pick + nPick) % mod;
    }

    ll tab(int n, int goal, int k)
    {
        vector<vector<long long>> dp(2, vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= goal; i++)
        {
            dp[i % 2][0] = 0;
            for (int j = 1; j <= min(i, n); j++)
            {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] * (n - (j - 1)) % mod;
                if (j > k)
                    dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][j] * (j - k)) % mod;
            }
        }

        return dp[goal % 2][n];
    }
    int numMusicPlaylists(int n, int goal, int k)
    {

        return tab(n, goal, k);
    }
};