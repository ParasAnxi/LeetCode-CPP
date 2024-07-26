class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        int mini = INT_MAX;
        int ans;
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for (auto i : edges)
        {
            adj[i[0]][i[1]] = i[2];
            adj[i[1]][i[0]] = i[2];
        }
        for (int i = 0; i < n; i++)
        {
            queue<pair<int, int>> q;
            q.push({i, 0});
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            int count = 0;

            while (!q.empty())
            {
                auto it = q.front();
                q.pop();

                int node = it.first;
                int d = it.second;

                for (int j = 0; j < adj.size(); j++)
                {
                    if (adj[node][j] > 0 && d + adj[node][j] <= distanceThreshold && dist[j] >= d + adj[node][j])
                    {
                        dist[j] = d + adj[node][j];
                        q.push({j, dist[j]});
                    }
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (dist[j] <= distanceThreshold && i != j)
                    count++;
            }

            if (count <= mini)
            {
                mini = count;
                ans = i;
            }
        }
        return ans;
    }
};