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
  int leastBricks(vector<vector<int>> &wall) {
    int n = wall.size();
    mll mp;
    int i = 0;
    while (i < n) {
      ll sum = 0;
      for (int j = 0; j < (wall[i].size() - 1); j++) {
        sum += wall[i][j];
        mp[sum]++;
      }
      i++;
    }
    int ans = n;
    for (auto i : mp) {
      ans = min(ans, (int)(n - i.second));
    }
    return ans;
  }
};