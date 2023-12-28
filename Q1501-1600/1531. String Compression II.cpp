class Solution
{
public:
    int solve(int index, int rem, int last, int freq, string &s, vector<vector<vector<vector<int>>>> &dp)
    {
        if (index == s.size())
        {
            return 0;
        }
        if (dp[index][rem][last][freq] != -1)
        {
            return dp[index][rem][last][freq];
        }
        int take = INT_MAX;
        int notTake = INT_MAX;
        if (rem > 0)
        {
            notTake = solve(index + 1, rem - 1, last, freq, s, dp);
        }
        int inc = freq == 9 || freq == 99 || freq == 1;
        if (s[index] - 'a' == last)
        {
            take = solve(index + 1, rem, s[index] - 'a', freq + 1, s, dp) + inc;
        }
        else
        {
            take = solve(index + 1, rem, s[index] - 'a', 1, s, dp) + 1;
        }
        return dp[ind][rem][last][freq] = min(take, notTake);
    }
    int getLengthOfOptimalCompression(string s, int k)
    {
        vector<vector<vector<vector<int>>>> dp(s.size(), vector<vector<vector<int>>>(k + 1, vector<vector<int>>(27, vector<int>(101, -1))));
        return solve(0, k, 26, 0, s, dp);
    }
};