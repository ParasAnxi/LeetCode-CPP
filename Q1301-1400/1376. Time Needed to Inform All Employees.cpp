class Solution {
public:
    vector<vector<int>> adj;

    void adj_ini(int n, vector<int>& manager){
        adj.resize(n);
        for(int i = 0; i < n; i++){
            int x = manager[i];
            if (x != -1)
                adj[x].push_back(i);
        }
    }

    int timeNeed = 0;

    void dfs(int i, int time, vector<int>& informTime){
        timeNeed = max(timeNeed, time);
        for(auto v: adj[i])
            dfs(v, time + informTime[i], informTime);
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime){
        adj_ini(n, manager);
        dfs(headID, 0, informTime);
        return timeNeed;
    }
};