class Solution
{
public:
    int N = 1e6;
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;

        int n = routes.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++)
        {
            for (auto el : routes[i])
                m[el].push_back(i);
        }

        queue<int> q;
        vector<bool> vis_node(n, false), vis(N, false);
        vector<int> level(N, 0);

        for (auto el : m[source])
        {
            vis_node[el] = true;
            for (auto stops : routes[el])
            {
                if (!vis[stops])
                {
                    q.push(stops);
                    vis[stops] = true;
                    level[stops] = 1;
                }
            }
        }

        while (!q.empty())
        {
            int fr = q.front();
            q.pop();
            if (fr == target)
                return level[fr];
            for (auto el : m[fr])
            {
                if (!vis_node[el])
                {
                    vis_node[el] = true;
                    for (auto stops : routes[el])
                    {
                        if (!vis[stops])
                        {
                            q.push(stops);
                            level[stops] = level[fr] + 1;
                            vis[stops] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};