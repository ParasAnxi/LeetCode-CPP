class Solution
{
    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &graph, vector<string> &itinerary, const string &airport)
    {
        while (!graph[airport].empty())
        {
            string next = graph[airport].top();
            graph[airport].pop();
            dfs(graph, itinerary, next);
        }

        itinerary.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        vector<string> itinerary;

        for (const vector<string> &ticket : tickets)
        {
            graph[ticket[0]].push(ticket[1]);
        }

        dfs(graph, itinerary, "JFK");

        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};