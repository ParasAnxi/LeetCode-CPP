

class Solution
{
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> bobTime;
    int maxProfit;

    bool dfsBob(int node, int time, vector<bool> &visited)
    {
        visited[node] = true;
        bobTime[node] = time;
        if (node == 0)
            return true;
        for (int neighbor : graph[node])
        {
            if (!visited[neighbor] && dfsBob(neighbor, time + 1, visited))
                return true;
        }
        bobTime.erase(node);
        return false;
    }

public:
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &profit)
    {
        int n = profit.size();
        maxProfit = INT_MIN;

        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        dfsBob(bob, 0, visited);

        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, 0);
        fill(visited.begin(), visited.end(), false);

        while (!q.empty())
        {
            auto [node, time, income] = q.front();
            q.pop();

            if (!bobTime.count(node) || bobTime[node] > time)
                income += profit[node];
            else if (bobTime[node] == time)
                income += profit[node] / 2;

            if (graph[node].size() == 1 && node != 0)
            {
                maxProfit = max(maxProfit, income);
            }

            for (int neighbor : graph[node])
            {
                if (!visited[neighbor])
                    q.emplace(neighbor, time + 1, income);
            }
            visited[node] = true;
        }
        return maxProfit;
    }
};