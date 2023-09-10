class Solution
{
public:
    int mod = 1e9 + 7;
    unsigned long int solve(int n, int p, int d, vector<vector<int>> &dp)
    {
        if (p == n && d == n)
            return 1;
        if (dp[p][d] != -1)
            return dp[p][d];
        if (p > d)
        {
            if (p < n)
            {
                unsigned long int a = ((n - p) * solve(n, p + 1, d, dp)) % mod;
                unsigned long int b = ((p - d) * solve(n, p, d + 1, dp)) % mod;
                return dp[p][d] = a + b;
            }
            else
            {
                unsigned long int a = ((p - d) * solve(n, p, d + 1, dp)) % mod;
                return dp[p][d] = a;
            }
        }
        else
        {
            unsigned long int a = ((n - p) * solve(n, p + 1, d, dp)) % mod;
            return dp[p][d] = a;
        }
    }
    int countOrders(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n, 0, 0, dp);
    }
};