class Solution {
private:
  long long solve(string &s, int n, bool flg, int limit, int m, long long t,
                   vector<vector<long long>> &dp) {
    if (n == m) {
      if (!flg)
        return 1ll;
      else {
        string temp = s.substr(s.length() - m);
        long long ele = stoll(temp);
        return ele >= t ? 1ll : 0ll;
      }
    }

    if (n < m)
      return 0ll;

    if (dp[n][flg] != -1)
      return dp[n][flg];

    int ub = flg ? s[s.length() - n] - '0' : 9;
    long long ans = 0;

    for (int i = 0; i <= min(ub, limit); i++) {
      ans += solve(s, n - 1, flg & (ub == i), limit, m, t, dp);
    }

    return dp[n][flg] = ans;
  }

public:
  long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
    string startS = to_string(start - 1);
    string finishF = to_string(finish);
    long long st = stoll(s);

    vector<vector<long long>> dp(17, vector<long long>(2, -1));
    long long left = solve(startS, startS.length(), 1, limit, s.length(), st, dp);

    dp.assign(17, vector<long long>(2, -1));
    long long right = solve(finishF, finishF.length(), 1, limit, s.length(), st, dp);

    return (right - left);
  }
};