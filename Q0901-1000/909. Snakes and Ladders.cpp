class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<int>jump(n*n+1,0);
        
        int i=n-1,direction =1;
        
        int inc=1;
        
        for(;i>=0;i--)
        {
            if(direction==1)
            {
                for(int j=0;j<n;j++)
                {
                    if(arr[i][j]!=-1)
                    {
                        jump[inc]=arr[i][j];
                    }
                    inc++;
                }
                direction =-1;
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                    if(arr[i][j]!=-1)
                    {
                        jump[inc]=arr[i][j];
                    }
                    inc++;
                }
                direction=1;
            }
        }
        vector<vector<int>>adj(500);
        for(int i=1;i<n*n;i++)
        {
            for(int j=1;j<=6;j++)
            {
                int x=i+j;
                if(x<=n*n)
                {
                    if(jump[x]==0) adj[i].push_back(x);
                    else adj[i].push_back(jump[x]);
                }
            }
        }
        
        vector<int>dist(n*n+1,INT_MAX);
        queue<int>q;
        q.push(1);
        dist[1]=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr])
            {
                if(dist[it]==INT_MAX)
                {
                    q.push(it);
                    dist[it]=dist[curr]+1;
                }
            }
        }
        
        
        return dist[n*n]==INT_MAX?-1:dist[n*n];
    }
};