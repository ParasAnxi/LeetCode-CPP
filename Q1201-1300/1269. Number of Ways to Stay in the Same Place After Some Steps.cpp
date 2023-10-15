class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(int index, int steps, int n, vector<vector<int>> &dp)
    {
        if (steps == 0 && index == 0)
        {
            return 1;
        }
        if (index < 0 || index >= n || steps == 0)
        {
            return 0;
        }
        if (dp[index][steps] != -1)
        {
            return dp[index][steps];
        }
        long long right = solve(index + 1, steps - 1, n, dp) % mod;
        long long left = solve(index - 1, steps - 1, n, dp) % mod;
        long long same = solve(index, steps - 1, n, dp) % mod;
        return dp[index][steps] = (left + right + same) % mod;
    }
    int numWays(int steps, int arrLen)
    {
        arrLen = min(steps, arrLen);
        vector<vector<int>> dp(arrLen, vector<int>(steps + 1, -1));
        return solve(0, steps, arrLen, dp);
    }
};