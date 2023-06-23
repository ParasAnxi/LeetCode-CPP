class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
      int n=nums.size();
    int dp[n+1][1005];
    memset(dp,0,sizeof(dp));
    int len=2;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int dif=nums[j]-nums[i]+500;
            dp[j][dif]=max(dp[i][dif]+1,2);
            len=max(len,dp[j][dif]);   
        }   
    }
    return len;
    }
};