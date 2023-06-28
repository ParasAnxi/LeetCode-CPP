class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        int m = edges.size();
        for(int i = 0; i < m; i++){
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];   
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<double> prob(n,0.0);
        vector<int> visited(n,0);
        set<pair<double,int>> st;
        st.insert({0,start});
        prob[start] = 1.0;
        while(st.size() > 0){
            auto node = *st.begin();
            st.erase(st.begin());
            int u = node.second;
            if(visited[u])
                continue;
            visited[u] = 1;
            for(auto &child : adj[u]){
                int v = child.first;
                double weight = child.second;
                if(prob[u] * weight > prob[v]){
                    prob[v] = prob[u] * weight ;
                    st.insert({1.0 - prob[v],v});   
                }
            }
        }
        return prob[end];
    }
};