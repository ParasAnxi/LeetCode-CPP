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
  vll solve(int n) {
    vll ans;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        ans.pb(i);
        if (i != n / i)
          ans.pb(n / i);
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
  long long minArraySum(vector<int> &nums) {
    umii mp;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      vll vF = solve(nums[i]);
      for (int j = 0; j < vF.size(); j++) {
        if (nums[i] % vF[j] == 0 && mp.find(vF[j]) != mp.end()) {
          nums[i] = vF[j];
          break;
        }
      }
      mp[nums[i]]++;
    }
    ll ans = accumulate(nums.begin(), nums.end(), 0LL);
    return ans;
  }
};