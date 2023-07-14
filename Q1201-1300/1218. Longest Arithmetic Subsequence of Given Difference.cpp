class Solution
{
public:
    int dfs(vector<int> &arr, unordered_map<int, vector<int>> &mp, int d, int i, vector<int> &dp){
        if (dp[i] != -1){
            return dp[i];
        }
        int ele = arr[i] + d;

        int ans = 0;
        for (auto j : mp[ele]){
            if (i < j){
                ans = max(ans, 1 + dfs(arr, mp, d, j, dp));
            }
        }
        return dp[i] = ans;
    }
    int longestSubsequence(vector<int> &arr, int difference){
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); i++){
            mp[arr[i]].push_back(i);
        }
        int ans = 0;
        vector<int> dp(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++){
            ans = max(ans, dfs(arr, mp, difference, i, dp));
        }

        return ans + 1;
    }
};