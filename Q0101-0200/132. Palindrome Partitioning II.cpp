class Solution {
public:
  int solve(string &s, int idx, vector<int> &dp, vector<vector<int>> &vP) {
    int n = s.size();
    if (idx == n)
      return -1;

    if (dp[idx] != -1)
      return dp[idx];

    int mini = 1e9;
    for (int i = idx; i < n; i++) {
      if (vP[idx][i]) {
        mini = min(mini, 1 + solve(s, i + 1, dp, vP));
      }
    }
    return dp[idx] = mini;
  }
  int minCut(string s) {
    int n = s.size();
    vector<vector<int>> vP(n, vector<int>(n, 0));
    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++) {
      vP[i][i] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
      vP[i][i + 1] = (s[i] == s[i + 1]);
    }

    for (int k = 3; k <= n; k++) {
      for (int i = 0; i < n - k + 1; i++) {
        int j = i + k - 1;

        if (s[i] == s[j])
          vP[i][j] = vP[i + 1][j - 1];
      }
    }
    return solve(s, 0, dp, vP);
  }
};