using ll = long long;
using ull = unsigned long long;
using ld = long double;
using cd = complex<double>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using pll = pair<ll, ll>;
using ppii = pair<int, pii>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using pis = pair<int, string>;
using vs = vector<string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using pli = pair<ll, int>;
using umii = unordered_map<int, int>;
using umcvi = unordered_map<char, vi>;
using umsi = unordered_map<string, int>;
using mivi = map<int, vi>;
using umci = unordered_map<char, int>;
#define pb push_back
#define MOD 1000000007
#define LMOD 1000000000000000007LL
class Solution {
public:
  long long minimumTotalDistance(vector<int> &robot,
                                 vector<vector<int>> &factory) {
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());
    int n = robot.size();
    int m = factory.size();
    vector<vll> dp(n + 1, vll(m + 1, LLONG_MAX));
    dp[0][0] = 0;
    for (int j = 1; j <= m; ++j) {
      int pos = factory[j - 1][0];
      int lim = factory[j - 1][1];

      for (int i = 0; i <= n; i++) {
        dp[i][j] = dp[i][j - 1];
        ll dist = 0;
        for (int k = 1; k <= lim && i - k >= 0; k++) {
          dist += abs(robot[i - k] - pos);
          if (dp[i - k][j - 1] != LLONG_MAX &&
              dist < LLONG_MAX - dp[i - k][j - 1]) {
            dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + dist);
          }
        }
      }
    }

    return dp[n][m];
  }
};