class Solution
{
public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n + 1);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, 0);
        vector<int> comp;

        auto bfsMd = [&](int start) -> int
        {
            queue<int> q;
            vector<int> depth(n + 1, -1);
            q.push(start);
            depth[start] = 1;
            int maxDepth = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (int neighbor : adj[node])
                {
                    if (depth[neighbor] == -1)
                    {
                        depth[neighbor] = depth[node] + 1;
                        maxDepth = max(maxDepth, depth[neighbor]);
                        q.push(neighbor);
                    }
                }
            }
            return maxDepth;
        };

        function<bool(int, int)> is_bipartite = [&](int node, int col)
        {
            queue<int> q;
            q.push(node);
            color[node] = col;
            comp.push_back(node);

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (int neighbor : adj[curr])
                {
                    if (color[neighbor] == 0)
                    {
                        color[neighbor] = -color[curr];
                        q.push(neighbor);
                        comp.push_back(neighbor);
                    }
                    else if (color[neighbor] == color[curr])
                    {
                        return false;
                    }
                }
            }
            return true;
        };

        int result = 0;

        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 0)
            {
                comp.clear();
                if (!is_bipartite(i, 1))
                {
                    return -1;
                }
                int maxDepth = 0;
                for (int node : comp)
                {
                    maxDepth = max(maxDepth, bfsMd(node));
                }
                result += maxDepth;
            }
        }

        return result;
    }
};