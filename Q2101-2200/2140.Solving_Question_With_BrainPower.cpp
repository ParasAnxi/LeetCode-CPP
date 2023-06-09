class Solution {
public:
    long long recur(vector<vector<int>>& arr, int n){
        vector<long long> dp(n, 0);
        dp[n-1] = arr[n-1][0];
        for(int i = n - 2; i >= 0; i--){
            long long points = arr[i][0];
            int next = arr[i][1] + 1;
            if(i + arr[i][1] + 1 < n){
                dp[i] = max((points + dp[i + next]), dp[i+1]);
            }
            else{
                dp[i] = max(points, dp[i+1]);
            }
        }
        return dp[0];
    }
    long long mostPoints(vector<vector<int>>& arr) {   
        int n = arr.size();
        return recur(arr, n);
    }
};