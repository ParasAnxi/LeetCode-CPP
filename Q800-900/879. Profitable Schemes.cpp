class Solution {
public:
int ans=0;
int m=1e9+7;
int sumi(int ind, int target, int remainingPeople, vector<int> &group, vector<int> &profit, vector<vector<vector<int>>> &dp){
    if(ind<0){
        if(target>0) return 0;
        else return 1;
    }
    if(target<0) target=0;
    if(dp[ind][target][remainingPeople]!=-1) return dp[ind][target][remainingPeople];
    int pick=0;
    if(remainingPeople>=group[ind]) pick=sumi(ind-1,target-profit[ind],remainingPeople-group[ind],group,profit,dp);
    int notPick=sumi(ind-1,target,remainingPeople,group,profit,dp);
    return dp[ind][target][remainingPeople]=(pick%m+notPick%m)%m;
}
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int len=profit.size();
        if(len==0) return 0;
        vector<vector<vector<int>>> dp(len,vector<vector<int>> (minProfit+1,vector<int> (n+1,-1)));
        return sumi(len-1,minProfit,n,group,profit,dp);
    }
};