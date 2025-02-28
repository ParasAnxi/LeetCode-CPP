class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string st;
        int i = m, j = n;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                st.push_back(str1[i - 1]);
                i--, j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                st.push_back(str1[i - 1]);
                i--;
            }
            else
            {
                st.push_back(str2[j - 1]);
                j--; // code with prince
            }
        }

        while (i > 0)
        {
            st.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0)
        {
            st.push_back(str2[j - 1]);
            j--;
        }

        reverse(st.begin(), st.end());
        return st;
    }
};