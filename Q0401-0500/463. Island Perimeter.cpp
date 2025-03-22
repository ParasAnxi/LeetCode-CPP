class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> v(n + 2, vector<int>(m + 2, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    v[i + 1][j + 1] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= m + 1; j++)
            {
                if (j <= m && v[i][j] == 0 && v[i][j + 1] == 1)
                    ans++;
                if (i <= n && v[i][j] == 0 && v[i + 1][j] == 1)
                    ans++;
                if (i > 0 && v[i][j] == 0 && v[i - 1][j] == 1)
                    ans++;
                if (j > 0 && v[i][j] == 0 && v[i][j - 1] == 1)
                    ans++;
            }
        }
        return ans;
    }
};