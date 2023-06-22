class Solution {
public:

int getAns(vector<int> &prices,int ind,int buy,int n,int fee,vector<vector<int>> &dp){
    if(ind==n) 
        return 0;     
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    int profit;
    if(buy==0){
        profit = max(0+getAns(prices,ind+1,0,n,fee,dp), -prices[ind] + getAns(prices,ind+1,1,n,fee,dp));
    }
    if(buy==1){
        profit = max(0+getAns(prices,ind+1,1,n,fee,dp), prices[ind] -fee + getAns(prices,ind+1,0,n,fee,dp));
    }
    return dp[ind][buy] = profit;
}
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    if(prices.size()==0) return 0;
    int ans = getAns(prices,0,0,prices.size(),fee,dp);
    return ans;
    }
};