class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> graph(n + 1);
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> distance(n + 1, vector<int>(2, INT_MAX));
        distance[1][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 1, 0});

        while (!pq.empty())
        {
            auto [dis, u, k] = pq.top();
            pq.pop();

            if (dis > distance[u][k]){
                continue;
            }

            for (int v : graph[u])
            {
                int newDis = dis + time + ((dis / change) % 2 == 1 ? change - (dis % change) : 0);

                if (newDis < distance[v][0])
                {
                    distance[v][1] = distance[v][0];
                    distance[v][0] = newDis;
                    pq.push({newDis, v, 0});
                }
                else if (newDis < distance[v][1] && newDis != distance[v][0])
                {
                    distance[v][1] = newDis;
                    pq.push({newDis, v, 1});
                }
            }
        }
        return distance[n][1];
    }
};