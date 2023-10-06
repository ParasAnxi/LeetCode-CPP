class Solution
{
public:
    int integerBreak(int n)
    {
        if (n <= 3)
            return n - 1;

        vector<int> dp(n + 1, 0);
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++)
            for (int j = 1; j <= i / 2; j++)
                dp[i] = max(dp[i], dp[j] * dp[i - j]);

        return dp[n];
    }
};