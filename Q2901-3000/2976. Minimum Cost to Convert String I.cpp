class Solution
{
public:
    void minCost(vector<vector<int>> &dp){
        int n = dp.size();
        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX && dp[i][k] + dp[k][j] < dp[i][j]){
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        int n = 26;
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < original.size(); i++)
        {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            dp[x][y] = min(dp[x][y], cost[i]);
        }
        minCost(dp);
        long long ans = 0;
        for (int i = 0; i < source.size(); i++)
        {
            if (source[i] == target[i])
                continue;
            else
            {
                int x = source[i] - 'a';
                int y = target[i] - 'a';
                if (dp[x][y] == INT_MAX)
                    return -1;
                ans += dp[x][y];
            }
        }

        return ans;
    }
};