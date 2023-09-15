class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<int> vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int ans = 0;
        while (!pq.empty())
        {
            int cost = pq.top().first, ind = pq.top().second;
            pq.pop();
            if (vis[ind])
                continue;
            vis[ind] = 1;
            ans += cost;
            for (int i = 1; i < n; i++)
            {
                if (vis[i])
                    continue;
                int dis = abs(points[ind][0] - points[i][0]) + abs(points[ind][1] - points[i][1]);
                pq.push({dis, i});
            }
        }
        return ans;
    }
};