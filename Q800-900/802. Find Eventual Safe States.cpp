class Solution {
public:
    map<int, int> safe;
    vector<int> res;
    map<int,int>visited;
    bool dfs(int node, vector<vector<int>>& graph) {
        if(!visited[node]){
            visited[node]=1;
        if (safe.find(node) != safe.end()) return safe[node];
        for (auto i : graph[node]) {
            if (!dfs(i, graph)) {
                safe[node]=0;
                return false;
            }
        }
        
        safe[node] = 1;
        return true;
    }
    return safe[node];
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        for (int i = 0; i < graph.size(); i++) {
            if (dfs(i, graph)) {
                res.push_back(i);
            }
        }
        return res;
    }
};