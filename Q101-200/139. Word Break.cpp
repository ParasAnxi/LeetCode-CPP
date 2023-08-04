class Solution{
public:
    bool wordBreak(string s, vector<string> &wordDict){
        int x, y;
        x = s.size();
        y = wordDict.size();
        bool dp[x + 1];
        dp[0] = true;
        for (int i = 1; i <= x; i++)
            dp[i] = false;
        for (int i = 1; i <= x; i++){
            dp[i] = false;
            for (int j = 0; j < y; j++){
                int wordSize = wordDict[j].size();
                if (i >= wordSize && s.substr(i - wordSize, wordSize) == wordDict[j]){
                    dp[i] = dp[i] || dp[i - wordSize];
                }
                if (dp[i])
                    break;
            }
        }
        return dp[x];
    }
};