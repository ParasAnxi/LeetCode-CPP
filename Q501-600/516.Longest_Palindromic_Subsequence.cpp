class Solution {
public:
    int dp[1005][1005];
    int helper(string& str, int left, int right){
        if(left > right)
            return 0;
        if(left == right)
            return 1;
        if(dp[left][right] != -1)
            return dp[left][right];
        if(str[left] == str[right])
            return dp[left][right] = 2 + helper(str, left + 1, right - 1);
        else{
            return dp[left][right] = max(helper(str, left + 1, right), helper(str, left, right - 1));
        }
    }
    int longestPalindromeSubseq(string str) {   
        int n = str.size();
        memset(dp, -1, sizeof(dp));
        return helper(str, 0, n - 1);
    }
};