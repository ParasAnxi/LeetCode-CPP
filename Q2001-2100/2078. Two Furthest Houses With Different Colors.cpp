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
  int maxDistance(vector<int> &colors) {
    unordered_map<int, pii> mp;
    int n = colors.size();
    for (int i = 0; i < n; i++) {
      if (mp.find(colors[i]) == mp.end()) {
        mp[colors[i]] = {i, i};
      } else {
        auto p = mp[colors[i]];
        mp[colors[i]] = {p.first, i};
      }
    }
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      for (auto j : mp) {
        if (colors[i] != j.first) {
          maxi =
              max(maxi, max(abs(j.second.first - i), abs(j.second.second - i)));
        }
      }
    }
    return maxi;
  }
};