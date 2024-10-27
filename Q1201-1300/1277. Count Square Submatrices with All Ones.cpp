class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
            ans += dp[0][j];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (matrix[i][j] == 1)
                {

                    int left = j > 0 ? dp[i][j - 1] : 0;
                    int leftAns = 0;
                    if (i > 0 and j > 0)
                    {
                        leftAns = dp[i - 1][j - 1];
                    }
                    int top = i > 0 ? dp[i - 1][j] : 0;

                    dp[i][j] = 1 + min(left, min(leftAns, top));
                }

                ans += dp[i][j];
            }
        }

        return ans;
    }
};