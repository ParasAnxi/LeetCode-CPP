class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (auto i : nums) {
      sum += i;
    }
    if (sum % 2 != 0) {
      return false;
    }
    int x = sum / 2;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (auto i : nums) {
      for (int j = x; j >= i; j--) {
        dp[j] = dp[j] || dp[j - i];
      }
    }
    return dp[x];
  }
};