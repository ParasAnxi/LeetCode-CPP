class Solution
{
public:
    int maxMoves(vector<vector<int>> &grid)
    {

        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
        int maxi = 0;

        for (int j = 0; j < dp.size(); j++)
        {
            dp[j][0] = 1;
        }

        for (int i = 1; i < grid[0].size(); i++)
        {
            bool next = false;
            for (int j = 0; j < grid.size(); j++)
            {

                bool b1 = false, b2 = false, b3 = false;

                if (j - 1 >= 0)
                {
                    b1 = (dp[j - 1][i - 1] != 0 && grid[j - 1][i - 1] < grid[j][i]);
                }

                if (j + 1 < grid.size())
                {
                    b2 = (dp[j + 1][i - 1] != 0 && grid[j + 1][i - 1] < grid[j][i]);
                }

                b3 = (dp[j][i - 1] != 0 && grid[j][i - 1] < grid[j][i]);

                if (b1 || b2 || b3)
                {
                    dp[j][i] = i;
                    maxi = max(maxi, dp[j][i]);
                    next = true;
                }
            }
            if (next == false)
            {
                break;
            }
        }
        return maxi;
    }
};