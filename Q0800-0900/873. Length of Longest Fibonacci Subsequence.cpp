class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 1; i < n; i++)
        {
            int k = i + 1;
            for (int j = 0; j < i; j++)
            {
                dp[i][j] = max(dp[i][j], 2);
                int num = arr[i] + arr[j];
                while (k < n && arr[k] < num)
                    k++;
                if (k < n && arr[k] == num)
                {
                    dp[k][i] = max(dp[k][i], dp[i][j] + 1);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans < 3 ? 0 : ans;
    }
};