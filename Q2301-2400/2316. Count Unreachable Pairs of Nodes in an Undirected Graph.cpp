class Solution {
public:
    void dfs(vector<int>g[],vector<bool>&vis,int node,long long &num_nodes){
        
     vis[node]=true;

    for(auto x:g[node]){
       if(vis[x]==false){
           num_nodes++;
         dfs(g,vis,x,num_nodes);
         }
       }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<bool>vis(n,false);
        vector<int>g[n+1];
        long long res=0;

        for(auto x:edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        
        for(int i=0;i<n;i++){
            if(vis[i] == false){
                long long num_nodes=1;
                dfs(g,vis,i,num_nodes);
                int not_conn_nodes=n-num_nodes;
                res+=(num_nodes*not_conn_nodes);
            }
                
        }
        return res/2;
    }
};