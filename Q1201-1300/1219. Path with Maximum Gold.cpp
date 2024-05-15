class Solution
{
public:
    vector<vector<int>> v;
    int dfs(int x, int y, vector<vector<int>> &grid)
    {
        v[x][y] = 1;
        int top = 0, left = 0, down = 0, right = 0;
        if (x - 1 >= 0 && !v[x - 1][y] && grid[x - 1][y])
        {
            top = dfs(x - 1, y, grid);
        }
        if (y - 1 >= 0 && !v[x][y - 1] && grid[x][y - 1])
        {
            left = dfs(x, y - 1, grid);
        }
        if (x + 1 < grid.size() && !v[x + 1][y] && grid[x + 1][y])
        {
            down = dfs(x + 1, y, grid);
        }
        if (y + 1 < grid[0].size() && !v[x][y + 1] && grid[x][y + 1])
        {
            right = dfs(x, y + 1, grid);
        }
        v[x][y] = 0;
        return max(left, max(right, max(top, down))) + grid[x][y];
    }
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int ans = 0;
        v.resize(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!v[i][j] && grid[i][j])
                {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};