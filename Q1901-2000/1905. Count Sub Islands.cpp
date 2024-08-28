class Solution
{
public:
    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int r, int c, vector<vector<int>> &dir, bool &isPos)
    {

        if (r < 0 || c < 0 || r >= grid2.size() || c >= grid2[0].size())
            return;
        if (grid2[r][c] == 2 || grid2[r][c] == 0)
            return;
        if (grid1[r][c] != grid2[r][c])
        {
            isPos = false;
            return;
        }
        grid2[r][c] = 2;
        for (auto d : dir)
        {
            int dr = r + d[0];
            int dc = c + d[1];
            dfs(grid1, grid2, dr, dc);
        }
    }
        int countSubIslands(vector<vector<int>> & grid1, vector<vector<int>> & grid2)
        {
            vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            bool isPos = true;
            int m = grid1.size(), n = grid1[0].size();
            int res = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid2[i][j] == 1)
                    {
                        isPos = true;
                        dfs(grid1, grid2, i, j, dir, isPos);
                        if (isPos)
                            res++;
                    }
                }
            }
            return res;
        }
    };