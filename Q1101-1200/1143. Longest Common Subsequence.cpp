class Solution
{
public:
    int solve(string &a, string &b, int i, int j)
    {
        if (i == a.length() || j == b.length())
        {
            return 0;
        }
        int ans = 0;
        if (a[i] == b[j])
        {
            ans = 1 + solve(a, b, i + 1, j + 1);
        }
        else
        {
            ans = max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
        }
        return ans;
    }
    int mem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if (i == a.length() || j == b.length())
        {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (a[i] == b[j])
        {
            ans = 1 + mem(a, b, i + 1, j + 1, dp);
        }
        else
        {
            ans = max(mem(a, b, i + 1, j, dp), mem(a, b, i, j + 1, dp));
        }
        return dp[i][j] = ans;
    }
    int tab(string &a, string &b)
    {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int so(string &a, string &b)
    {
        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);
        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = 1 + next[j + 1];
                }
                else
                {
                    ans = max(next[j], curr[j + 1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2)
    {

        return so(text1, text2);
    }
};