class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> cord = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            for (auto &cor : cord)
            {
                int row = r + cor[0];
                int col = c + cor[1];
                if (row >= 0 && col >= 0 && row < m && col < n && grid[row][col] == 0)
                {
                    grid[row][col] = grid[r][c] + 1;
                    q.push({row, col});
                }
            }
        }
        auto cmp = [](const tuple<int, int, int> &a, const tuple<int, int, int> &b)
        {
            return get<0>(b) > get<0>(a);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> pq(cmp);
        pq.push({grid[0][0], 0, 0});
        int res = INT_MAX;
        while (!pq.empty())
        {
            auto [dis, r, c] = pq.top();
            pq.pop();
            res = min(res, dis);
            if (r == m - 1 && c == n - 1)
                return res - 1;
            for (auto &cor : cord)
            {
                int row = r + cor[0];
                int col = c + cor[1];
                if (row >= 0 && col >= 0 && row < m && col < m && grid[row][col] > 0)
                {
                    pq.push({grid[row][col], row, col});
                    grid[row][col] = 0;
                }
            }
        }
        return 0;
    }
};