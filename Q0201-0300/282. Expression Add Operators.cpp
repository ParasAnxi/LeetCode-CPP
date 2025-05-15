class Solution {
public:
  void solve(string &num, int tar, vector<string> &ans, long x, long prev,
             int idx, string s) {
    if (idx == num.length()) {
      if (x == tar) {
        ans.push_back(s);
      }
      return;
    }
    for (int i = idx; i < num.length(); i++) {
      string currS = num.substr(idx, i - idx + 1);
      long currN = stol(currS);
      if (i > idx && num[idx] == '0')
        break;
      if (idx == 0) {
        solve(num, tar, ans, currN, currN, i + 1, currS);
      } else {
        solve(num, tar, ans, x + currN, currN, i + 1, s + "+" + currS);
        solve(num, tar, ans, x - currN, -currN, i + 1, s + "-" + currS);
        solve(num, tar, ans, x - prev + (prev * currN), prev * currN, i + 1,
              s + "*" + currS);
      }
    }
  }
  vector<string> addOperators(string num, int target) {
    vector<string> ans;
    solve(num, target, ans, 0, 0, 0, "");
    return ans;
  }
};
