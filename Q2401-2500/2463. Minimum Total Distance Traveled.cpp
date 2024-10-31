class Solution
{
public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
        dp[0][0] = 0;

        for (int j = 1; j <= m; ++j)
        {
            int position = factory[j - 1][0];
            int limit = factory[j - 1][1];

            for (int i = 0; i <= n; ++i)
            {
                dp[i][j] = dp[i][j - 1];

                long long distance = 0;
                for (int k = 1; k <= limit && i - k >= 0; ++k)
                {
                    distance += abs(robot[i - k] - position);
                    if (dp[i - k][j - 1] != LLONG_MAX && distance < LLONG_MAX - dp[i - k][j - 1])
                    {
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + distance);
                    }
                }
            }
        }

        return dp[n][m];
    }
};