class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        dp[0][0]=true;
        for(int j=0;j<=m;j++)
            dp[0][j] = true;
        for(int j=1; j<=m; j++){
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*') 
                    dp[0][j] = false;
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==p[j-1] or p[j-1]=='?') 
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*') 
                    dp[i][j] = dp[i-1][j] or dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};