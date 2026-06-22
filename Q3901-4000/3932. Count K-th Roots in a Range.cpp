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
  ll pow(ll b, int e, ll lim) {
    if (b == 0)
      return (e == 0) ? 1 : 0;
    if (b == 1 || e == 0)
      return 1;
    ll ans = 1;
    for (int i = 0; i < e; ++i) {
      if (ans > lim / b)
        return lim + 1;
      ans *= b;
    }
    return ans;
  }
  int countLessThanOrEqual(int target, int k) {
    if (target < 0) {
      return 0;
    }
    if (k == 1) {
      return target + 1;
    }
    int mini = 0;
    sqrt(target) int maxi = sqrt(target);
    int ans = 0;
    while (mini <= maxi) {
      int mid = mini + (maxi - mini) / 2;
      if (pow(mid, k, target) <= target) {
        ans = mid;
        mini = mid + 1;
      } else {
        maxi = mid - 1;
      }
    }
    return ans + 1;
  }

  int countKthRoots(int l, int r, int k) {
    if (l > r)
      return 0;
    return countLessThanOrEqual(r, k) - countLessThanOrEqual(l - 1, k);
  }
};