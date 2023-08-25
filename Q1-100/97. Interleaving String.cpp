class Solution
{
public:
    bool f(int i, int j, int x, string &s1, string &s2, string &s3, int dp[101][101][202])
    {
        if (dp[i][j][x] != -1)
            return dp[i][j][x];

        if (x > s3.length())
            return dp[i][j][x] = 0;
        if (i == s1.length() && j == s2.length() && x == s3.length())
            return dp[i][j][x] = 1;

        if (i >= s1.length() && j >= s2.length())
            return dp[i][j][x] = 0;

        bool l = 0, r = 0;
        if (i < s1.length() && s1[i] == s3[x])
            l = f(i + 1, j, x + 1, s1, s2, s3, dp);
        if (j < s2.length() && s2[j] == s3[x])
            r = f(i, j + 1, x + 1, s1, s2, s3, dp);

        return dp[i][j][x] = l || r;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int dp[101][101][202] = {0};
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                for (int k = 0; k < 202; k++)
                    dp[i][j][k] = -1;

        return f(0, 0, 0, s1, s2, s3, dp);
    }
};