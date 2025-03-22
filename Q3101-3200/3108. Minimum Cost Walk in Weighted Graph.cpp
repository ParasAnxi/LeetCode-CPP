class Solution
{
public:
    int f(vector<vector<pair<int, int>>> &adj, int i, vector<int> &vis,int count, vector<int> &res)
    {
        int mini = INT_MAX;

        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty())
        {

            int num = q.front();
            res[num] = count;
            q.pop();
            for (auto it : adj[num])
            {
                mini = mini & it.second;
                if (!vis[it.first])
                {
                    vis[it.first] = 1;
                    q.push(it.first);
                }
            }
        }
        return mini;
    }

    vector<int> minimumCost(int n, vector<vector<int>> &edges,vector<vector<int>> &query)
    {
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        int count = 0;
        vector<int> vis(n, 0);
        vector<int> res(n, 0);
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                arr.push_back(f(adj, i, vis, count, res));
                count++;
            }
        }
        vector<int> ans;
        for (auto it : query)
        {
            int initial = it[0];
            int final = it[1];

            if (res[initial] == res[final])
            {
                ans.push_back(arr[res[initial]]);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};