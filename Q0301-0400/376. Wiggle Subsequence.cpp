class Solution {
public:
  vector<vector<vector<int>>> dp;

  int solve(vector<int> &nums, int index, int prev, int tig) {
    if (index == nums.size())
      return 0;

    if (dp[index][prev + 1][tig] != -1)
      return dp[index][prev + 1][tig];

    int inc = 0;
    int exc = 0;

    exc = solve(nums, index + 1, prev, tig);

    if (prev == -1) {
      inc = max(inc, 1 + solve(nums, index + 1, index, tig));
    }

    if (prev != -1) {
      if (tig == 1) {
        if (nums[index] < nums[prev]) {
          inc = max(inc, 1 + solve(nums, index + 1, index, 1 - tig));
        }
      } else {
        if (nums[index] > nums[prev]) {
          inc = max(inc, 1 + solve(nums, index + 1, index, 1 - tig));
        }
      }
    }

    return dp[index][prev + 1][tig] = max(inc, exc);
  }

  int wiggleMaxLength(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return 1;
    if (n == 2) {
      if (nums[0] == nums[1])
        return 1;
      return 2;
    }

    dp = vector<vector<vector<int>>>(
        n, vector<vector<int>>(n + 1, vector<int>(2, -1)));

    int ans1 = solve(nums, 0, -1, 0);
    int ans2 = solve(nums, 0, -1, 1);

    return max(ans1, ans2);
  }
};