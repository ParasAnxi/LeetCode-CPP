#define mod 1000000007
class Solution
{
public:
    int solve(int n, int k)
    {
        if (k <= 0)
            return k == 0;
        int ans = 0;
        for (int i = 0; i <= k && i < n; i++)
        {
            ans = (ans + solve(n - 1, k - i)) % mod;
        }
        return ans;
    }
    int mem(int n, int k, vector<vector<int>> &dp)
    {
        if (k <= 0)
            return k == 0;
        if (dp[n][k] != -1)
            return dp[n][k];
        int ans = 0;
        for (int i = 0; i <= k && i < n; i++)
        {
            ans = (ans + mem(n - 1, k - i, dp)) % mod;
        }
        return dp[n][k] = ans;
    }
    int tab(int n, int k)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                for (int x = 0; x <= min(j, i - 1); x++)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % mod;
                }
            }
        }
        return dp[n][k];
    }
    int so(int n, int k)
    {
        vector<int> prev(k + 1, 0), curr(k + 1, 0);

        curr[0] = prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                curr[j] = (prev[j] + (j > 0 ? curr[j - 1] : 0)) % mod;
                curr[j] = (curr[j] + mod - (j >= i ? prev[j - i] : 0)) % mod;
            }
            prev = curr;
        }
        return curr[k];
    }
    int kInversePairs(int n, int k)
    {
        // return solve(n,k);
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return so(n, k);
    }
};