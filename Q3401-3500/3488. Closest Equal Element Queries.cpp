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
  vector<int> solveQueries(vector<int> &nums, vector<int> &queries) {
    int n = nums.size();
    vi vD(n);
    umii vNi;
    vi vNe(n);
    for (int i = 0; i < nums.size(); i++) {
      int x = nums[i];
      vNi[x] = i;
    }
    for (int i = 0; i < n; i++) {
      int x = nums[i];
      int dist = n + i - vNi[x];
      vNi[x] = n + i;
      if (dist > n - 1) {
        vNe[i] = -1;
      } else {
        vNe[i] = dist;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      int x = nums[i];
      vNi[x] = n - 1 - i;
    }
    for (int i = n - 1; i >= 0; i--) {
      int x = nums[i];
      int dist = 2 * n - 1 - i - vNi[x];
      vNi[x] = 2 * n - 1 - i;
      if (dist <= n - 1) {
        vNe[i] = min(dist, vNe[i]);
      }
    }
    vi ans(queries.size());
    for (int i = 0; i < queries.size(); i++) {
      ans[i] = vNe[queries[i]];
    }
    return ans;
  }
};