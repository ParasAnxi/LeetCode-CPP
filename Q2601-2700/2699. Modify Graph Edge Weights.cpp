class Solution
{
public:
    int solve(int n, vector<pair<int, int>> adj[], int s, int d, int tar)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        q.push({0, s});
        vector<int> dis(n, 2e9);
        dis[s] = 0;
        while (!q.empty())
        {

            int node = q.top().second;
            q.pop();
            for (auto i : adj[node])
            {
                int child = i.first;
                int wt = i.second;
                if (dis[child] > dis[node] + wt)
                {
                    dis[child] = dis[node] + wt;
                    q.push({dis[child], child});
                }
            }
        }

        return dis[d];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int s, int d, int tar)
    {
        vector<vector<int>> ans;
        vector<pair<int, int>> adj[n];
        vector<int> v;
        for (int j = 0; j < edges.size(); j++)
        {
            vector<int> i = edges[j];
            if (i[2] != -1)
            {
                adj[i[0]].push_back({i[1], i[2]});
                adj[i[1]].push_back({i[0], i[2]});
            }

            else
                v.push_back(j);
        }

        int dis = solve(n, adj, s, d, tar);
        if (dis < tar)
        {
            return ans;
        }

        if (dis == tar)
        {
            for (auto i : edges)
            {

                if (i[2] == -1)
                    ans.push_back({i[0], i[1], 2000000000});
                else
                    ans.push_back({i[0], i[1], i[2]});
            }

            return ans;
        }

        bool flag = false;

        for (auto i : edges)
        {
            if (i[2] != -1)
            {
                ans.push_back({i[0], i[1], i[2]});
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            adj[edges[v[i]][0]].push_back({edges[v[i]][1], 1});
            adj[edges[v[i]][1]].push_back({edges[v[i]][0], 1});
            int dis = solve(n, adj, s, d, tar);
            if (dis <= tar)
            {
                ans.push_back({edges[v[i]][0], edges[v[i]][1], tar - dis + 1});

                for (int j = i + 1; j < v.size(); j++)
                {
                    ans.push_back({edges[v[j]][0], edges[v[j]][1], 2000000000});
                }
                return ans;
            }
            else
            {
                ans.push_back({edges[v[i]][0], edges[v[i]][1], 1});
            }
        }
        return {};
    }
};