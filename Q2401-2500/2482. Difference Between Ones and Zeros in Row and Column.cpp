class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(), 0));
        unordered_map<int, int> rowone;
        unordered_map<int, int> colone;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    rowone[i]++;
                    colone[j]++;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                ans[i][j] = rowone[i] + colone[j] - (n - rowone[i]) - (m - colone[j]);
            }
        }
        return ans;
    }
};