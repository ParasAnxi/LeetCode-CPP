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
  int maximumSum(vector<int> &nums) {
    vi v1, v2, v3;
    for (auto i : nums) {
      int p = i % 3;
      if (p == 0) {
        v1.pb(i);
      } else if (p == 1) {
        v2.pb(i);
      } else {
        v3.pb(i);
      }
    }
    int ans = 0;
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());
    sort(v3.begin(), v3.end(), greater<int>());
    if (v1.size() >= 3) {
      ans = max(ans, v1[0] + v1[1] + v1[2]);
    }
    if (v2.size() >= 3) {
      ans = max(ans, v2[0] + v2[1] + v2[2]);
    }
    if (v3.size() >= 3) {
      ans = max(ans, v3[0] + v3[1] + v3[2]);
    }
    if (v1.size() >= 1 && v2.size() >= 1 && v3.size() >= 1) {
      ans = max(ans, v1[0] + v2[0] + v3[0]);
    }
    return ans;
  }
};