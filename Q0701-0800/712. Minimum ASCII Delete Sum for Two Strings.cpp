class Solution
{
public:
    int solve(int i, int j, string &s1, string &s2,
              vector<vector<int>> &dp)
    {
        if (i >= s1.length() || j >= s2.length())
        {
            int ans = 0;
            while (j < s2.length())
                ans += int(s2[j++]);
            while (i < s1.length())
                ans += int(s1[i++]);
            return ans;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
        {
            return dp[i][j] = solve(i + 1, j + 1, s1, s2, dp);
        }
        else
        {
            int exc1 = int(s1[i]) + solve(i + 1, j, s1, s2, dp);
            int exc2 = int(s2[j]) + solve(i, j + 1, s1, s2, dp);

            return dp[i][j] = min(exc1, exc2);
        }
    }

    int minimumDeleteSum(string s1, string s2)
    {
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
        return solve(0, 0, s1, s2, dp);
    }
};