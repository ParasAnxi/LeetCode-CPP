class Solution
{
public:
    int solve(string s, int i, bool flag, vector<vector<int>> &dp)
    {
        if (i == s.length())
        {
            if (flag)
            {
                return 0;
            }
            return 1;
        }

        if ((s[i] == '0') && flag == false)
        {
            return 0;
        }
        if (s[i] >= '7' && flag && s[i - 1] >= '2')
        {
            return 0;
        }
        if (dp[i][flag] != -1)
        {
            return dp[i][flag];
        }
        int ans = 0;
        if (s[i] <= '2' && flag == false)
        {
            ans += solve(s, i + 1, true, dp);
        }
        ans += solve(s, i + 1, false, dp);
        return dp[i][flag] = ans;
    }
    int numDecodings(string s)
    {
        vector<vector<int>> dp(s.length(), vector<int>(2, -1));
        return solve(s, 0, false, dp);
    }
};