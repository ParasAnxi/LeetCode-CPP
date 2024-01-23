class Solution
{
public:
    int solve(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += solve(i - 1) * solve(n - i);
        }
        return ans;
    }
    int mem(int n, vector<int> &dp)
    {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += mem(i - 1, dp) * mem(n - i, dp);
        }
        return dp[n] = ans;
    }
    int tab(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
    int cat(int n)
    {
        long long int ans = 1;
        for (int i = 1; i <= n; i++)
            ans = (ans * (4 * i - 2)) / (i + 1);
        return ans;
    }
    int numTrees(int n)
    {
        // return solve(n);
        // vector<int>dp(n+1,-1);
        // return mem(n,dp);
        // return tab(n);
        return cat(n);
    }
};