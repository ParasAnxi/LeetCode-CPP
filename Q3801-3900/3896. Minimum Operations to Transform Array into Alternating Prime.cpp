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
  vi seive(int n) {
    vi vP(n + 1, 1);
    vP[0] = vP[1] = 0;
    for (int i = 2; i <= sqrt(n); i++) {
      if (vP[i]) {
        for (int j = i * i; j <= n; j += i) {
          vP[j] = 0;
        }
      }
    }
    return vP;
  }
  int minOperations(vector<int> &nums) {
    int maxi = 0;
    for (auto i : nums) {
      maxi = max(maxi, i);
    }
    maxi += 100;
    vi vPr = seive(maxi);
    vi vI;
    vi vP;
    for (int i = 1; i <= maxi; i++) {
      if (vPr[i]) {
        vP.pb(i);
      } else {
        vI.pb(i);
      }
    }
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i % 2 == 0) {
        if (!vPr[nums[i]]) {
          auto id = upper_bound(vP.begin(), vP.end(), nums[i]);
          ans += (*id - nums[i]);
        }
      } else {
        if (vPr[nums[i]]) {
          auto id = upper_bound(vI.begin(), vI.end(), nums[i]);
          ans += (*id - nums[i]);
        }
      }
    }

    return ans;
  }
};