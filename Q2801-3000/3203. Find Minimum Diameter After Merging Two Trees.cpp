class Solution
{
public:
    int bfs(int node, vector<int> &vis, vector<vector<int>> &adj)
    {
        int a = node;
        int farthestNode = node;
        int distance = 0;
        queue<int> q;
        vis[node] = 1;
        q.push(node);

        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                int frontNode = q.front();
                q.pop();
                farthestNode = frontNode;
                for (auto i : adj[frontNode])
                {
                    if (vis[i] == 0)
                    {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
            distance++;
        }
        return (a == 0) ? farthestNode : distance - 1;
    }

    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        int n1 = edges1.size() + 1;
        vector<vector<int>> adj1(n1);
        for (auto i : edges1)
        {
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }

        int n2 = edges2.size() + 1;
        vector<vector<int>> adj2(n2);
        for (auto i : edges2)
        {
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        vector<int> vis(n1, 0);

        int diameterFirstend1 = bfs(0, vis, adj1);
        fill(vis.begin(), vis.end(), 0);
        int distance1 = bfs(diameterFirstend1, vis, adj1);

        vis.clear();
        vis.resize(n2, 0);

        int diameterFirstend2 = bfs(0, vis, adj2);
        fill(vis.begin(), vis.end(), 0);
        int distance2 = bfs(diameterFirstend2, vis, adj2);
        int totalDiameter = (distance1 + 1) / 2 + (distance2 + 1) / 2 + 1;

        return max({totalDiameter, distance1, distance2});
    }
};