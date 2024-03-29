class Solution {
public:
	int mod=1000000007;

long long int dp[101][201];
long long int getAns(vector<int>& locations, int start, int finish, int fuel){
            
    long long currans=0;
    if(start==finish){
        currans++;
    }
    if(fuel <= 0)
        return dp[start][fuel]=currans;
    
    if(dp[start][fuel]!=-1){
        return dp[start][fuel];
    }
    for(int i=0;i<locations.size();i++){
        if(start!=i && fuel>=abs(locations[start]-locations[i])){
            
            currans=(currans%mod+getAns(locations, i, finish, fuel-abs(locations[start]-locations[i]) ) % mod)%mod ;
        }   
    }  
    return dp[start][fuel]= currans%mod;
 }
int countRoutes(vector<int>& locations, int start, int finish, int fuel) { 
    memset(dp,-1,sizeof(dp));        
    return getAns(locations, start, finish, fuel);
}
};