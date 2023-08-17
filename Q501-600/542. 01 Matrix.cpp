class Solution
{
public:
    int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visit(n, vector<int>(m, 999999));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                    visit[i][j] = 0;
                }
            }
        }

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                pair<int, int> temp = q.front();
                int x = temp.first;
                int y = temp.second;
                q.pop();
                for (auto dir : dirs)
                {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (visit[nx][ny] > 1 + visit[x][y])
                    {
                        visit[nx][ny] = 1 + visit[x][y];
                        q.push({nx, ny});
                    }
                }
            }
        }
        return visit;
    }
};