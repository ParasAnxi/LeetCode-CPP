class Solution
{
public:
    int solve(vector<int> &value, int i, int j)
    {
        if (i + 1 == j)
        {
            return 0;
        }
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, value[i] * value[j] * value[k] + solve(value, i, k) + solve(value, k, j));
        }
        return ans;
    }
    int mem(vector<int> &v, int i, int j, vector<vector<int>> &dp)
    {
        if (i + 1 == j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, v[i] * v[j] * v[k] + mem(v, i, k, dp) + mem(v, k, j, dp));
        }
        return dp[i][j] = ans;
    }
    int tab(vector<int> &values, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    ans = min(ans, values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n - 1];
    }
    int minScoreTriangulation(vector<int> &values)
    {
        // return solve(values,0,values.size()-1);
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1));
        // return mem(values,0,values.size()-1,dp);
        int n = values.size();
        return tab(values, n);
    }
};