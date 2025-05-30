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
using umii = unordered_map<int, int>;
using umcvi = unordered_map<char, vi>;
using umci = unordered_map<char, int>;
#define pb push_back
#define MOD 1000000007
#define LMOD 1000000000000000007LL
class Solution {
public:
  int solve(int s, int e, int k, vi &inp,vvvi &dp) {
    if (s > e)
      return 0;
    if (dp[s][e][k] != -1)
      return dp[s][e][k];
    int ans = (k + 1) * (k + 1) + solve(s + 1, e, 0, inp, dp);
    for (int i = s + 1; i <= e; ++i) {
      if (inp[i] == inp[s]) {
        ans = max(ans, solve(s + 1, i - 1, 0, inp, dp) +solve(i, e, k + 1, inp, dp));
      }
    }
    return dp[s][e][k] = ans;
  }

  int removeBoxes(vector<int> &input) {
    int n = input.size();
   vvvi dp(n,vvi(n, vi(n, -1)));
    return solve(0, n - 1, 0, input, dp);
  }
};
