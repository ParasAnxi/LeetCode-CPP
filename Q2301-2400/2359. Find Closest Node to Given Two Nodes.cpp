class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int a = edges.size();
        vector<int> dist1(a, INT_MAX);
        queue<int> q;
        q.push(node1);
        dist1[node1] = 0;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            int v = edges[u];
            if(v!=-1 && dist1[v] == INT_MAX){
                dist1[v] = dist1[u]+1;
                q.push(v);
            }
        }
		
        vector<int> dist2(a, INT_MAX);
		
        vector<int> res(a, INT_MAX);
        
        queue<int> q1;
        q1.push(node2);
        dist2[node2] = 0;
        res[node2] = max(dist1[node2], dist2[node2]);
        
        while(!q1.empty()){
            int u = q1.front();
            q1.pop();
            int v= edges[u];
            if(v!=-1 && dist2[v] == INT_MAX){
                dist2[v] = dist2[u]+1;
                q1.push(v);
                res[v] = max(dist1[v], dist2[v]);
            }
        }
        
		int flag=0;
        for(int i=0; i<res.size(); i++){
            if(res[i]!=INT_MAX)
                flag =1;
        }
        if(flag==0)
            return -1;
		
		int ans=0; 
        for(int i=1; i<res.size(); i++){
            if(res[i]<res[ans])
                ans = i;
        }
        return ans;
    }
};