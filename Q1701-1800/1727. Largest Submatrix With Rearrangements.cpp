class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<map<int, int>> dp(m);
        for (int x = 0; x < n; ++x)
        {
            int streak = 0;
            for (int y = 0; y < m; ++y)
            {
                if (matrix[y][x])
                    ++streak;
                else
                    streak = 0;

                ++dp[y][streak];
            }
        }

        int ans = 0;
        for (int y = 0; y < m; ++y)
        {
            int curCount = 0;
            for (auto it = dp[y].rbegin(); it != dp[y].rend(); ++it)
            {
                curCount += it->second;
                ans = max(ans, curCount * it->first);
            }
        }
    }
};