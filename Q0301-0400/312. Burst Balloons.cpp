class Solution {
public:
  int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
    if (i > j) {
      return 0;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    int maxi = INT_MIN;
    int ans;
    for (int k = i; k <= j; k++) {
      int ans = arr[i - 1] * arr[k] * arr[j + 1] + solve(arr, i, k - 1, dp) +
                solve(arr, k + 1, j, dp);
      maxi = max(maxi, ans);
    }
    return maxi;
  }
  int solveTab(vector<int> &nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size() - 2;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--) {
      for (int j = i; j <= n; j++) {
        int maxi = 0;
        for (int idx = i; idx <= j; idx++) {
          int cost = nums[i - 1] * nums[idx] * nums[j + 1] + dp[i][idx - 1] +
                     dp[idx + 1][j];
          maxi = max(maxi, cost);
        }
        dp[i][j] = maxi;
      }
    }

    return dp[1][n];
  }
  int maxCoins(vector<int> &nums) {
    // nums.insert(nums.begin(), 1);
    // nums.insert(nums.end(), 1);
    // int n = nums.size();
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return solve(nums, 1, n - 2, dp);
    return solveTab(nums);
  }
};