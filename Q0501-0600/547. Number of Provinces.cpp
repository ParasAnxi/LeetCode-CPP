class Solution {
public:
    vector<bool> visited;
    void dfs(int i, vector<vector<int>>& isConnected, int n){
        visited[i]=1;
        for(int j=0; j<n; j++){
            if(isConnected[i][j]==1 && visited[j]==0)
                dfs(j, isConnected, n);
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int comp=0;
        visited.assign(n, 0);
        for(int i=0; i<n; i++)
            if (visited[i]==0){
                comp++;
                dfs(i, isConnected, n);
            }
        return comp;       
    }
};