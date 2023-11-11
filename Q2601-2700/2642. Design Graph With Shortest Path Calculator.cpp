class Graph
{
public:
    vector<pair<int, int>> adj[101];
    Graph(int n, vector<vector<int>> &edges)
    {
        for (auto &i : edges)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }
    }

    void addEdge(vector<int> edge)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node1});
        vector<int> dist(101, INT_MAX);
        dist[node1] = 0;
        while (pq.size())
        {
            auto u = pq.top().second;
            pq.pop();
            for (auto &[v, cost] : adj[u])
            {
                if (dist[u] + cost < dist[v])
                {
                    dist[v] = dist[u] + cost;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */