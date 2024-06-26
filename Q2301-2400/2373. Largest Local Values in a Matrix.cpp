class Solution
{
public:
    int solve(int row, int col, vector<vector<int>> &grid)
    {
        int num = grid[row][col];
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                num = max(num, grid[row + i][col + j]);
            }
        }
        return num;
    }
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                ans[i][j] = solve(i + 1, j + 1, grid);
            }
        }
        return ans;
    }
};