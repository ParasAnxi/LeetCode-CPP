class Solution
{
public:
    int solve(int i, int cut, vector<int> &jobDiff, int n, vector<vector<int>> &dp)
    {
        if (cut == 0)
        {
            int ans = jobDiff[i];
            for (int j = i + 1; j < n; ++j)
            {
                ans = max(ans, jobDiff[j]);
            }
            return dp[i][cut] = ans;
        }
        if (n - i <= cut)
            return 1e8;

        if (dp[i][cut] != -1)
            return dp[i][cut];

        int temp = jobDiff[i];
        int ans = 1e8;
        for (int j = i; j < n - 1; ++j)
        {
            temp = max(temp, jobDiff[j]);
            ans = min(temp + solve(j + 1, cut - 1, jobDiff, n, dp), ans);
        }
        return dp[i][cut] = ans;
    }

public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (d - 1 >= n)
            return -1;
        vector<vector<int>> dp(n, vector<int>(d, -1));
        return solve(0, d - 1, jobDifficulty, n, dp);
    }
};