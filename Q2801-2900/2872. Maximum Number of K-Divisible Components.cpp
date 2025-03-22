class Solution
{
public:
    pair<int, long long> solve(vector<int> adj[], int u, vector<int> &values, int k, vector<bool> &vis)
    {
        vis[u] = true;
        int count = 0;
        long long sum = values[u];
        for (int v : adj[u])
        {
            if (vis[v])
                continue;
            auto p = solve(adj, v, values, k, vis);
            count += p.first;
            sum = sum + p.second;
        }
        if (sum % k == 0)
        {
            count++;
        }
        return {count, sum};
    }
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        vector<int> adj[n];
        for (auto &v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int res = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            auto p = solve(adj, i, values, k, vis);
            res += p.first;
        }
        return res;
    }
};