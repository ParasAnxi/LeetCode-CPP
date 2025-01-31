class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), res = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<pair<int, int>>> islandMap(n, vector<pair<int, int>>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                islandMap[i][j] = {grid[i][j], 0};
            }
        }

        int islandNum = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j])
                {
                    res = max(res, bfs(islandMap, visited, i, j, islandNum));
                    islandNum++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!grid[i][j])
                {
                    unordered_map<int, int> islandSizes;
                    if (i - 1 >= 0 && islandMap[i - 1][j].first)
                        islandSizes[islandMap[i - 1][j].second] = islandMap[i - 1][j].first;
                    if (i + 1 < n && islandMap[i + 1][j].first)
                        islandSizes[islandMap[i + 1][j].second] = islandMap[i + 1][j].first;
                    if (j - 1 >= 0 && islandMap[i][j - 1].first)
                        islandSizes[islandMap[i][j - 1].second] = islandMap[i][j - 1].first;
                    if (j + 1 < n && islandMap[i][j + 1].first)
                        islandSizes[islandMap[i][j + 1].second] = islandMap[i][j + 1].first;

                    int sum = 1;
                    for (auto it : islandSizes)
                        sum += it.second;

                    res = max(res, sum);
                }
            }
        }
        return res;
    }

private:
    int bfs(vector<vector<pair<int, int>>> &grid, vector<vector<bool>> &visited, int i, int j, int num)
    {
        queue<pair<int, int>> q;
        vector<pair<int, int>> collect;
        int n = grid.size();
        q.push({i, j});

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            if (visited[r][c])
                continue;
            visited[r][c] = true;
            collect.push_back({r, c});

            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto [dr, dc] : directions)
            {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc].first)
                {
                    q.push({nr, nc});
                }
            }
        }

        for (auto [r, c] : collect)
        {
            grid[r][c] = {collect.size(), num};
        }
        return collect.size();
    }
};