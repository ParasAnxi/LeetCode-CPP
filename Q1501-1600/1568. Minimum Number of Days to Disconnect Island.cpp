class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &temp, int &rows, int &cols, vector<vector<int>> &direction)
    {
        if (i < 0 || j < 0 || i >= rows || j >= cols || temp[i][j] == 0)
        {
            return;
        }
        temp[i][j] = 0;
        for (int k = 0; k < 4; k++)
        {
            dfs(i + direction[k][0], j + direction[k][1], temp, rows, cols, direction);
        }
    }

    int solve(vector<vector<int>> &temp, int &rows, int &cols, vector<vector<int>> &direction)
    {
        int island = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (temp[i][j] == 1)
                {
                    dfs(i, j, temp, rows, cols, direction);
                    island++;
                }
            }
        }
        return island;
    }

    int minDays(vector<vector<int>> &grid)
    {
        vector<vector<int>> temp = grid;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int island = 0;
        island = solve(temp, rows, cols, direction);
        if (island == 1)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp = grid;
                    if (temp[i][j] == 1)
                    {
                        temp[i][j] = 0;
                        if (solve(temp, rows, cols, direction) != 1)
                            return 1;
                        temp[i][j] = 1;
                    }
                }
            }
            return 2;
        }
        return 0;
    }
};