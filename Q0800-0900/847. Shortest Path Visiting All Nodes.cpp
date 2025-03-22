class Solution
{
public:
    int sum = 0;
    int shortestPathLength(vector<vector<int>> &g)
    {
        vector<unordered_map<int, int>> v(g.size());
        int ans = INT_MAX;
        sum = (1 << g.size()) - 1;
        for (int i = 0; i < g.size(); ++i)
            ans = min(ans, dfs(g, v, i, 0));
        return ans;
    }
    int dfs(vector<vector<int>> &g, vector<unordered_map<int, int>> &v,
            int node, int cv)
    {
        if ((cv | (1 << node)) == sum)
            return 0;
        if (v[node].find(cv) != v[node].end())
            return v[node][cv];
        v[node][cv] = INT_MAX - 1;
        for (auto &e : g[node])
            v[node][cv] = min(v[node][cv], 1 + dfs(g, v, e, cv | (1 << node)));
        return v[node][cv];
    }
};