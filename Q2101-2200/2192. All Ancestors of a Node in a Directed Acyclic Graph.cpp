class Solution
{
public:
    vector<int> adj[1005];
    bool vis[1000];
    vector<int> solve(int node, vector<vector<int>> &ans)
    {
        if (adj[node].size() == 0)
            return {};
        if (vis[node] == true)
            return ans[node];
        vector<int> res;
        for (auto &i : adj[node])
        {
            res.push_back(i);
            vector<int> a = solve(i, ans);
            for (auto &y : a)
            {
                res.push_back(y);
            }
            sort(res.begin(), res.end());
            res.erase(unique(res.begin(), res.end()), res.end());
        }
        ans[node] = res;
        vis[node] = true;
        return res;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        for (auto &x : edges)
        {
            adj[x[1]].push_back(x[0]);
        }
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++)
        {
            solve(i, ans);
        }
        return ans;
    }
};