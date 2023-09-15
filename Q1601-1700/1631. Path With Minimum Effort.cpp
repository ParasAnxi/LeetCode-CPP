class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        q.push({0, {0, 0}});
        dist[0][0] = 0;
        while (!q.empty())
        {
            int dis = q.top().first;
            int i = q.top().second.first;
            int j = q.top().second.second;
            q.pop();
            if (i == n - 1 && j == m - 1)
                return dis;
            for (int k = 0; k < 4; k++)
            {
                int newr = i + dr[k];
                int newc = j + dc[k];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m)
                {
                    int cost = abs(heights[i][j] - heights[newr][newc]);
                    cost = max(cost, dis);
                    if (cost < dist[newr][newc])
                    {
                        dist[newr][newc] = cost;
                        q.push({cost, {newr, newc}});
                    }
                }
            }
        }
        return -1;
    }
};