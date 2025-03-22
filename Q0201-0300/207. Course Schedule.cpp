class Solution {
public:
    bool canFinish(int num , vector<vector<int>>& pre) {
        vector<int> adj[num];
        vector<int> topo; 
        for(auto it: pre){
           adj[it[1]].push_back(it[0]);

        }
        vector<int> indegree(num,0);
        for(int i=0;i<num;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(indegree[i]==0){
                q.push(i);
                }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==num){
            return true;

        }
        return false;
    }
};