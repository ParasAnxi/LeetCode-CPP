class Solution
{
public:
    int solve(vector<int> &satisfaction, int index, int time)
    {
        if (index == satisfaction.size())
            return 0;

        int include = satisfaction[index] * time + solve(satisfaction, index + 1, time + 1);
        int exclude = solve(satisfaction, index + 1, time);
        return max(include, exclude);
    }
    int mem(vector<int> &s, int index, int time, vector<vector<int>> &dp)
    {
        if (index == s.size())
        {
            return 0;
        }
        if (dp[index][time] != -1)
            return dp[index][time];
        int include = s[index] * time + mem(s, index + 1, time + 1, dp);
        int exclude = mem(s, index + 1, time, dp);
        return dp[index][time] = max(include, exclude);
    }
    int tab(vector<int> &s)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                int include = s[index] * (time + 1) + dp[index + 1][time + 1];
                int exclude = dp[index + 1][time];
                dp[index][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int so(vector<int> &s)
    {
        int n = s.size();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                int include = s[index] * (time + 1) + next[time + 1];
                int exclude = next[time];
                next[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return mem(satisfaction,0,1,dp);
        // return tab(satisfaction);
        // return so(satisfaction);
        int sum = 0;
        int ans = 0;
        int cur = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            cur += sum + satisfaction[i];
            sum += satisfaction[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};