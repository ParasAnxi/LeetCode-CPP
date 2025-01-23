class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowC(m, 0);
        vector<int> colC(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    rowC[i]++;
                    colC[j]++;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] && (rowC[i] > 1 || colC[j] > 1))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};