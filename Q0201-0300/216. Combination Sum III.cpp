class Solution {
public:
  void solve(int index, int k, int n, vector<vector<int>> &ans,
             vector<int> &output) {
    if (n == 0) {
      if (output.size() == k) {
        ans.push_back(output);
      }
      return;
    }
    if (index > 9) {
      return;
    }
    output.push_back(index);
    solve(index + 1, k, n - index, ans, output);
    output.pop_back();
    solve(index + 1, k, n, ans, output);
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> output;
    solve(1, k, n, ans, output);
    return ans;
  }
};