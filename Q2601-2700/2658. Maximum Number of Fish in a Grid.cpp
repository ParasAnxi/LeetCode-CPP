class Solution
{
public:
    int dfs(int r1, int c1, vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int value = 0;

        for (int i = 0; i < 4; i++)
        {
            int nx = r1 + directions[i][0];
            int ny = c1 + directions[i][1];

            if (nx >= r || nx < 0 || ny >= c || ny < 0 || grid[nx][ny] == 0 || grid[nx][ny] == -1)
                continue;

            value += grid[nx][ny];
            grid[nx][ny] = -1;
            value += dfs(nx, ny, grid);
        }
        return value;
    }
    int findMaxFish(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();

        int ans = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] != 0 && grid[i][j] != -1)
                {
                    int value = grid[i][j];
                    grid[i][j] = -1;
                    value = value + dfs(i, j, grid);
                    ans = max(ans, value);
                }
            }
        }

        return ans;
    }
};