class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length(); 
        if (n != s2.length()) {
            return false;
        }
        bool dp[n + 1][n][n]; 
        memset(dp, false, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j]) {
                    dp[1][i][j] = true;
                }
            }
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                for (int j = 0; j <= n - l; j++) {
                    for (int k = 1; k < l; k++) {
                        if ((dp[k][i][j] && dp[l - k][i + k][j + k]) || (dp[k][i][j + l - k] && dp[l - k][i + k][j])) {
                            dp[l][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};