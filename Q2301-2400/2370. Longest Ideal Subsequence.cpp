class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int dp[26] = {0};
        int ans = 0;
        for (char c : s)
        {
            int i = c - 'a';
            int a = max(0, i - k), b = min(i + k, 25);
            for (int j = a; j <= b; j++)
            {
                dp[i] = max(dp[i], dp[j]);
            }
            dp[i]++;
        }
        return *max_element(dp, dp + 26);
    }
};