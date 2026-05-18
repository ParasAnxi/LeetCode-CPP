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
  int mirrorFrequency(string s) {
    int ans = 0;
    vi vF(10);
    vi vC(26);
    for (auto ch : s) {
      if (ch >= '0' && ch <= '9') {
        vF[ch - '0']++;
      } else {
        vC[ch - 'a']++;
      }
    }
    for (int i = 0; i < 5; i++) {
      ans += abs(vF[i] - vF[9 - i]);
    }

    for (int i = 0; i < 13; i++) {
      ans += abs(vC[i] - vC[25 - i]);
    }
    return ans;
  }
};