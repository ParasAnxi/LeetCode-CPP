class Solution
{
public:
    int ans = 1;
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<int> v(n + 1, -1);
        vector<vector<int>> adj(n + 1);
        for (auto x : relations)
            adj[x[0]].push_back(x[1]);
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == -1)
                ans = max(ans, sol(i, v, adj, time));
        }
        return ans;
    }
    int sol(int i, vector<int> &v, vector<vector<int>> &adj, vector<int> &time)
    {
        if (v[i] != -1)
            return v[i];
        int m = time[i - 1];
        for (auto x : adj[i])
        {
            m = max(m, time[i - 1] + sol(x, v, adj, time));
        }
        return v[i] = m;
    }
};