class Solution {
public:
    void dfs(int s,vector<bool> &v,int &ans,vector<vector<vector<int>>> &g){
        if(v[s])return;
        v[s] = true;
        for(auto &i: g[s]){
            ans = min(ans,i[1]);
            dfs(i[0],v,ans,g);
        }
    }
        int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> g(n+1);
        for(int i = 0; i < roads.size(); i++){
            g[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            g[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        int ans = INT_MAX;
        vector<bool>  v(n+1,false);
        dfs(1,v,ans,g);
        return ans;
    }
};