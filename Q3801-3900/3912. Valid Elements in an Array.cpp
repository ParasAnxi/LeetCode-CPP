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
  vector<int> findValidElements(vector<int> &nums) {
    vi ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int flgL = 1;
      for (int j = 0; j < i; j++) {
        if (nums[i] <= nums[j]) {
          flgL = 0;
          break;
        }
      }
      bool flgR = 1;
      if (!flgL) {
        for (int j = i + 1; j < n; j++) {
          if (nums[i] <= nums[j]) {
            flgR = 0;
            break;
          }
        }
      }
      if (flgL || flgR) {
        ans.pb(nums[i]);
      }
    }
    return ans;
  }
};