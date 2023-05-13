class Solution {
    #define ll long long
public:
    ll mod=1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<ll>dp(high+1,0);
        dp[0]=1;
        ll ans=0;
        for(int i=1;i<=high;i++){
            if(i>=zero){
                dp[i] = (dp[i]%mod + dp[abs(zero-i)]%mod)%mod; 
            }
            if(i>=one){
                dp[i] = (dp[i]%mod + dp[abs(one-i)]%mod)%mod; 
            }
            if(i>=low){
                ans = (ans%mod + dp[i]%mod)%mod;
            }
        }
        return ans;
    }
};