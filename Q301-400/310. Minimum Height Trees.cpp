class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};

        vector<int> graph[n];
        vector<int> indegree(n, 0);
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            indegree[u]++;
            indegree[v]++;
        }

        queue<int> queue;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
            {
                queue.push(i);
            }
        }

        vector<int> result;
        while (!queue.empty())
        {
            result.clear();
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                int node = queue.front();
                queue.pop();
                result.push_back(node);
                for (auto neighbor : graph[node])
                {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 1)
                    {
                        queue.push(neighbor);
                    }
                }
            }
        }
        return result;
    }
};