class Solution {
public:
  int solve(int index, int buy, vector<int> &arr, int n) {
    if (index >= n)
      return 0;
    int profit;
    if (buy == 1) {
      profit = max(-arr[index] + solve(index + 1, 0, arr, n),
                   0 + solve(index + 1, 1, arr, n));
    } else {
      profit = max(arr[index] + solve(index + 2, 1, arr, n),
                   0 + solve(index + 1, 0, arr, n));
    }
    return profit;
  }
  int solveMem(int index, int buy, vector<int> &arr, int n,
               vector<vector<int>> &dp) {
    if (index >= n)
      return 0;
    int profit;
    if (buy == 1) {
      profit = max(-arr[index] + solveMem(index + 1, 0, arr, n, dp),
                   0 + solveMem(index + 1, 1, arr, n, dp));
    } else {
      profit = max(arr[index] + solveMem(index + 2, 1, arr, n, dp),
                   0 + solveMem(index + 1, 0, arr, n, dp));
    }
    return dp[index][buy] = profit;
  }
  int solveTab(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n + 2, vector<int>(3, 0));
    for (int index = n - 1; index >= 0; index--) {
      for (int buy = 0; buy < 2; buy++) {
        if (buy == 1) {
          dp[index][buy] =
              max(-arr[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
        } else {
          dp[index][buy] =
              max(arr[index] + dp[index + 2][1], 0 + dp[index + 1][0]);
        }
      }
    }
    return dp[0][1];
  }
  int solveSo(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n + 2, vector<int>(3, 0));
    vector<int> curr(n + 2, 0), next(n + 2, 0), cur(n + 2, 0);
    for (int index = n - 1; index >= 0; index--) {
      for (int buy = 0; buy < 2; buy++) {
        if (buy == 1) {
          cur[buy] = max(-arr[index] + curr[0], 0 + curr[1]);
        } else {
          cur[buy] = max(arr[index] + next[1], 0 + curr[0]);
        }
      }
      next = curr;
      curr = cur;
    }
    return cur[1];
  }
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    return solveSo(prices);
  }
};