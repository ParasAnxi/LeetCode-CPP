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
using umii = unordered_map<int, int>;
using umcvi = unordered_map<char, vi>;
using umci = unordered_map<char, int>;
#define pb push_back
#define MOD 1000000007
#define LMOD 1000000000000000007LL
class Solution {
public:
  string optimalDivision(vector<int> &nums) {
    if (nums.size() == 2) {
      return to_string(nums[0]) + "/" + to_string(nums[1]);
    }
    string ans = to_string(nums[0]) + "/(";
    if (nums.size() == 1)
      return to_string(nums[0]);
    for (int i = 1; i < nums.size() - 1; ++i)
      ans += to_string(nums[i]) + "/";
    ans += to_string(nums.back()) + ")";
    return ans;
  }
};