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
  vector<int> minCost(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    int m = queries.size();
    vll vP(n, 0);
    vll vS(n, 0);
    for (int i = 0; i < n - 1; i++) {
      ll dR = (ll)nums[i + 1] - nums[i];
      ll dL = (i > 0) ? (ll)nums[i] - nums[i - 1] : LLONG_MAX;
      vP[i + 1] = vP[i] + (dR < dL ? 1 : dR);
    }
    for (int i = n - 1; i > 0; i--) {
      ll dL = (ll)nums[i] - nums[i - 1];
      ll dR = (i < n - 1) ? (ll)nums[i + 1] - nums[i] : LLONG_MAX;
      vS[i - 1] = vS[i] + (dL <= dR ? 1 : dL);
    }
    vi ans(m);
    for (int i = 0; i < m; i++) {
      int l = queries[i][0];
      int r = queries[i][1];
      if (l <= r) {
        ans[i] = (int)(vP[r] - vP[l]);
      } else {
        ans[i] = (int)(vS[r] - vS[l]);
      }
    }
    return ans;
  }
};