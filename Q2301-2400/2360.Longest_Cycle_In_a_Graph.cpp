class Solution {
public:
    
    void dfs(vector<int>& edges, int u, vector<bool>& vis, int &count){
        vis[u] = true;
        count++;
        if(edges[u] != -1 && vis[edges[u]] == false){
            dfs(edges, edges[u], vis, count);
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            int v = edges[i];
            if(v != -1){
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(edges[u] != -1){
                indegree[edges[u]]--;
                if(indegree[edges[u]] == 0){
                    q.push(edges[u]);
                }
            }
        }
        vector<bool> vis(n, false);
        int maxi = INT_MIN;   
        for(int i = 0; i < n; i++){
            int count = 0;
            if(indegree[i] > 0 && vis[i] == false){
                dfs(edges, i, vis, count);
            }
            
            maxi = max(maxi, count);
        }
        if(maxi == 0)
            return -1;
        return maxi;
    }
};