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
  int minMoves(vector<int> &nums, int limit) {
    int st = 0;
    int e = nums.size() - 1;
    vi vH(200001, 0);
    vi vMin, vMax;
    while (st <= e) {
      vH[nums[st] + nums[e]]++;
      vMin.pb(min(nums[st], nums[e]));
      vMax.pb(max(nums[st], nums[e]));
      st++;
      e--;
    }
    sort(vMin.begin(), vMin.end());
    sort(vMax.begin(), vMax.end());
    int ans = INT_MAX;
    for (int i = 0; i < vH.size(); i++) {
      if (vH[i] > 0) {
        ll sum = i;
        int idx = upper_bound(vMin.begin(), vMin.end(), sum - 1) - vMin.begin();
        int tM;
        if (limit <= sum) {
          int idx1 =
              lower_bound(vMin.begin(), vMin.end(), sum - limit) - vMin.begin();
          tM = idx1 * 2 + (idx - idx1) + (vMin.size() - idx) * 2 - vH[i];
        } else {
          tM = idx + (vMin.size() - idx) * 2 - vH[i];
        }

        ans = min(ans, tM);
      }
    }
    for (int i = 0; i < vH.size(); i++) {
      if (vH[i] > 0) {
        ll sum = i;
        int idx = upper_bound(vMax.begin(), vMax.end(), sum - 1) - vMax.begin();
        int tM;
        if (limit <= sum) {
          int idx1 =
              lower_bound(vMax.begin(), vMax.end(), sum - limit) - vMax.begin();
          tM = idx1 * 2 + (idx - idx1) + (vMax.size() - idx) * 2 - vH[i];
        } else {
          tM = idx + (vMax.size() - idx) * 2 - vH[i];
        }
        ans = min(ans, tM);
      }
    }
    return min(ans, (int)vMin.size());
  }
};