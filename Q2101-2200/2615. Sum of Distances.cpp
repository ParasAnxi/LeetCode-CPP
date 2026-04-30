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
  using ll = long long;
  vector<long long> distance(vector<int> &nums) {
    int n = nums.size();
    vll ans(n);
    unordered_map<int, vi> mp;
    for (int i = 0; i < n; i++) {
      mp[nums[i]].pb(i);
    }
    for (auto &[_, k] : mp) {
      ll sum = 0;
      for (int i : k) {
        sum += i;
      }

      ll prS = 0;
      for (int i = 0; i < k.size(); i++) {
        int idx = k[i];
        ll pS = sum - prS - idx;

        ans[idx] += (idx * 1LL * i - prS);
        ans[idx] += (pS - idx * 1LL * (k.size() - i - 1));

        prS += idx;
      }
    }

    return ans;
  }
};