using ll = long long;
using ull = unsigned long long;
using ld = long double;
using cd = complex<double>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using pll = pair<ll, ll>;
using pci = pair<char, int>;
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
  int solve(int n) {
    int ans = 0;
    while (n) {
      ans = ans * 10 + (n % 10);
      n /= 10;
    }
    return ans;
  }

  int minMirrorPairDistance(vector<int> &nums) {
    umii mp;
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      if (mp.find(nums[i]) != mp.end()) {
        ans = min(ans, i - mp[nums[i]]);
      }
      mp[solve(nums[i])] = i;
    }
    return ans == INT_MAX ? -1 : ans;
  }
};