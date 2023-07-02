class Solution {
public:
    int ans;
    void solve(int idx,vector<vector<int>>& req,vector<int>& indeg,vector<int>& outdeg,int cnt){
        int n = indeg.size();
        if(idx>=req.size()){
            for(int i=0;i<n;i++){
                if((indeg[i]-outdeg[i])!=0)
                return;
            }
            ans = max(ans,cnt);
            return;
        }
        int a = req[idx][0];
        int b = req[idx][1];
        indeg[b]++;
        outdeg[a]++;
        solve(idx+1,req,indeg,outdeg,cnt+1);
        indeg[b]--;
        outdeg[a]--;
        solve(idx+1,req,indeg,outdeg,cnt);
    }
    int maximumRequests(int n, vector<vector<int>>& req) {
        vector<int> indeg(n),outdeg(n);
        ans = 0;
        solve(0,req,indeg,outdeg,0);
        return ans;
    }
};