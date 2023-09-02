class Solution
{
public:
    int dp[50];

    int minExtraChar(string s, vector<string> &dictionary)
    {
        int n = s.length();
        int m = dictionary.size();
        for (int i = 0; i < n; i++)
        {
            int mx = 0;
            for (int j = 0; j < i; j++)
            {
                mx = max(mx, dp[j]);
            }
            dp[i] = max(dp[i], mx);
            for (int j = 0; j < m; j++)
            {
                int sz = dictionary[j].size();
                if (i + sz - 1 < n)
                {
                    if (s.substr(i, sz) == dictionary[j])
                    {
                        dp[i + sz - 1] = max(dp[i + sz - 1], mx + sz);
                    }
                }
            }
        }
        return n - dp[n - 1];
    }
};