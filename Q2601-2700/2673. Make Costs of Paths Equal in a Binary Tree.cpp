class Solution {
public:
  int solve(int i, int n, vector<int> &cost, int &ans) {
    if (i > n)
      return 0;
    int left = solve(2 * i, n, cost, ans);
    int right = solve(2 * i + 1, n, cost, ans);
    ans += abs(left - right);
    return cost[i - 1] + max(left, right);
  }
  int minIncrements(int n, vector<int> &cost) {
    int ans = 0;
    solve(1, n, cost, ans);
    return ans;
  }
};