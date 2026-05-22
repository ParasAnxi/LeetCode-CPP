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
  ll solve(vi &nums, int pos, bool exc, vector<vll> &dp) {
    int n = nums.size();
    if (pos >= n - 1) {
      return 0;
    }
    if (dp[exc][pos] != -1) {
      return dp[exc][pos];
    }
    ll cost = max(0LL, (ll)max(nums[pos - 1], nums[pos + 1]) + 1LL - nums[pos]);
    ll ans = 0;
    if (exc) {
      ans = cost + solve(nums, pos + 2, true, dp);
    } else {
      ll op1 = cost + solve(nums, pos + 2, false, dp);
      ll op2 = cost + solve(nums, pos + 3, true, dp);
      ans = min(op1, op2);
    }
    return dp[exc][pos] = ans;
  }

  long long minIncrease(vector<int> &nums) {
    int n = nums.size();
    if (n < 3) {
      return 0;
    }
    if (n % 2 != 0) {
      ll ans = 0;
      for (int i = 1; i < n - 1; i += 2) {
        ans += max(0LL, (ll)max(nums[i - 1], nums[i + 1]) + 1LL - nums[i]);
      }
      return ans;
    }
    vector<vll> dp(2, vll(n + 2, -1));
    return min(solve(nums, 1, false, dp), solve(nums, 2, true, dp));
  }
};