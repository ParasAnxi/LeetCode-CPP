class Solution
{
    class comp
    {
    public:
        bool operator()(auto &A, auto &B)
        {
            return A[0] > B[0];
        }
    };

public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size(), n = heightMap[0].size(), ans = 0;
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++)
        {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for (int i = 0; i < n; i++)
        {
            pq.push({heightMap[0][i], 0, i});
            pq.push({heightMap[m - 1][i], m - 1, i});
            visited[0][i] = true;
            visited[m - 1][i] = true;
        }
        vector<int> dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int miniBondH = curr[0], currX = curr[1], currY = curr[2];
            for (vector<int> dir : dirs)
            {
                int nextX = currX + dir[0], nextY = currY + dir[1];
                if (nextX < 0 || nextY < 0 || nextX >= m || nextY >= n || visited[nextX][nextY])
                    continue;
                ans += max(0, miniBondH - heightMap[nextX][nextY]);
                pq.push({max(heightMap[nextX][nextY], miniBondH), nextX, nextY});
                visited[nextX][nextY] = true;
            }
        }
        return ans;
    }
};