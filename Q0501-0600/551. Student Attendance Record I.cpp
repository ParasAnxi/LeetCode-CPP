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
  bool checkRecord(string s) {
    int n = s.size();
    int late = 0;
    int notP = 0;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        late++;
        continue;

      } else if (s[i] == 'A') {
        notP++;
      }

      ans = max(ans, late);
      late = 0;
    }
    ans = max(ans, late);
    if (notP < 2 && ans < 3) {
      return true;
    }

    return false;
  }
};