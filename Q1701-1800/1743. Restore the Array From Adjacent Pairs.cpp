class Solution
{
public:
    void dfs(int node, map<int, vector<int>> &map, vector<int> &ans, unordered_map<int, int> &vis)
    {
        vis[node] = 1;
        vector<int> curAdj = map[node];
        ans.push_back(node);
        for (auto it : curAdj)
        {
            if (vis.find(it) == vis.end())
                dfs(it, map, ans, vis);
        }
        return;
    }
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        map<int, vector<int>> map;
        int n = adjacentPairs.size();
        for (int i = 0; i < adjacentPairs.size(); i++)
        {
            map[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            map[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        int first = 0;
        for (auto i : map)
        {
            if (i.second.size() == 1)
                first = i.first;
        }
        vector<int> ans;
        unordered_map<int, int> vis;
        dfs(first, map, ans, vis);
        return ans;
    }
};