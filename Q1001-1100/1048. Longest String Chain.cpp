class Solution
{
public:
    vector<vector<int>> dp;
    static bool comp(const string &a, const string &b)
    {
        return a.length() < b.length();
    }
    bool isPossible(string &a, string &b)
    {
        bool flag = false;
        for (int i = 0; i < a.length(); i++)
        {
            if (!flag && a[i] != b[i])
                flag = true;
            if (flag && a[i] != b[i + 1])
                return false;
        }
        return true;
    }
    bool check(string &a, string &b)
    {
        int n = a.length();
        int m = b.length();
        if (abs(n - m) != 1)
            return false;
        if (a.length() > b.length())
            return isPossible(b, a);
        return isPossible(a, b);
    }
    int solve(vector<string> &words, int i, int j)
    {
        if (i >= words.size())
            return 0;
        if (dp[i][j + 1] != -1)
            return dp[i][j + 1];
        if (j == -1 || check(words[i], words[j]))
            dp[i][j + 1] = max(dp[i][j + 1], 1 + solve(words, i + 1, i));
        return dp[i][j + 1] = max(dp[i][j + 1], solve(words, i + 1, j));
    }
    int longestStrChain(vector<string> &words)
    {
        dp = vector<vector<int>>(words.size(), vector<int>(words.size() + 1, -1));
        sort(words.begin(), words.end(), comp);
        return solve(words, 0, -1);
    }
};