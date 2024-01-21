class Solution
{
public:
    int solve(vector<int> &obstacle, int currlane, int pos)
    {
        int n = obstacle.size() - 1;
        if (pos == n)
        {
            return 0;
        }
        if (obstacle[pos + 1] != currlane)
        {
            return solve(obstacle, currlane, pos + 1);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (currlane != i && obstacle[pos] != i)
                {
                    ans = min(ans, 1 + solve(obstacle, i, pos + 1));
                }
            }
            return ans;
        }
    }
    int mem(vector<int> &obstacle, int currlane, int pos, vector<vector<int>> &dp)
    {
        int n = obstacle.size() - 1;
        if (pos == n)
        {
            return 0;
        }
        if (dp[currlane][pos] != -1)
        {
            return dp[currlane][pos];
        }
        if (obstacle[pos + 1] != currlane)
        {
            return mem(obstacle, currlane, pos + 1, dp);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (obstacle[pos] != i && currlane != i)
                {
                    ans = min(ans, 1 + mem(obstacle, i, pos, dp));
                }
            }
            return dp[currlane][pos] = ans;
        }
    }
    int tab(vector<int> &obstacle)
    {
        int n = obstacle.size() - 1;
        vector<vector<int>> dp(4, vector<int>(obstacle.size(), 1e9));
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;
        for (int pos = n - 1; pos >= 0; pos--)
        {
            for (int currlane = 1; currlane <= 3; currlane++)
            {
                if (obstacle[pos + 1] != currlane)
                {
                    dp[currlane][pos] = dp[currlane][pos + 1];
                }
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (obstacle[pos] != i && currlane != i)
                        {
                            ans = min(ans, 1 + dp[i][pos + 1]);
                        }
                    }
                    dp[currlane][pos] = ans;
                }
            }
        }
        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }
    int so(vector<int> &obstacle)
    {
        int n = obstacle.size() - 1;
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;
        for (int pos = n - 1; pos >= 0; pos--)
        {
            for (int currlane = 1; currlane <= 3; currlane++)
            {
                if (obstacle[pos + 1] != currlane)
                {
                    curr[currlane] = next[currlane];
                }
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (obstacle[pos] != i && currlane != i)
                        {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[currlane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(1 + next[1], 1 + next[3]));
    }
    int minSideJumps(vector<int> &obstacles)
    {
        // return solve(obstacles,2,0);
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        // return mem(obstacles,2,0,dp);
        // return tab(obstacles);
        return so(obstacles);
    }
};