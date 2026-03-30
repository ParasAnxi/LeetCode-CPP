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
  bool checkStrings(string s1, string s2) {
    vector<int> vO, vE, vO1, vE1;
    for (int i = 0; i < s1.size(); ++i) {
      if (i & 1) {
        vO.pb(s1[i]);
        vO1.pb(s2[i]);
      } else {
        vE.pb(s1[i]);
        vE1.pb(s2[i]);
      }
    }
    sort(vO.begin(), vO.end());
    sort(vO1.begin(), vO1.end());
    sort(vE.begin(), vE.end());
    sort(vE1.begin(), vE1.end());
    return (vO == vO1 and vE == vE1);
  }
};