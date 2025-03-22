class Solution
{
public:
    void solve(vector<vector<char>> &grid, int x, int y, int r, int c)
    {
        if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] != '1')
        {
            return;
        }
        grid[x][y] = 2;
        solve(grid, x + 1, y, r, c);
        solve(grid, x, y + 1, r, c);
        solve(grid, x - 1, y, r, c);
        solve(grid, x, y - 1, r, c);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size();
        if (row == 0)
        {
            return 0;
        }
        int col = grid[0].size();
        int ans = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    solve(grid, i, j, row, col);
                    ans += 1;
                }
            }
        }
        return ans;
    }
};