class Solution {
public:
  int getmaxiGenerated(int n) {
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    int maxi = dp[1];

    for (int i = 1; 2 * i <= n; i++) {
      dp[2 * i] = dp[i];
      maxi = max(maxi, dp[2 * i]);
      if (2 * i + 1 <= n) {
        dp[2 * i + 1] = dp[i] + dp[i + 1];
        maxi = max(maxi, dp[2 * i + 1]);
      }
    }
    return maxi;
  }
};