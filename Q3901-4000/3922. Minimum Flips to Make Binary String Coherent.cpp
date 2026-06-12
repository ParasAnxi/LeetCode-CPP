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
  int minFlips(string s) {
    int cO = 0;
    int cZ = 0;
    int n = s.length();
    int mini = n;
    for (auto ch : s) {
      if (ch == '1') {
        cO++;
      } else {
        cZ++;
      }
    }
    if (cZ == 0 || cO <= 1)
      return 0;
    if (cO == 2 && s[0] == '1' && s.back() == '1')
      return 0;
    mini = min(mini, cO - 1);
    mini = min(mini, cZ);
    int ans = 0;
    if (s[0] == '1') {
      cO--;
    } else {
      ans++;
    }
    if (s.back() == '1') {
      cO--;
    } else {
      ans++;
    }
    mini = min(mini, ans + cO);
    return mini;
  }
};