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
#define OS 100005
class Solution {
public:
  int longestBalanced(string s) {
    int n = s.length();
    vi vS(n + 1, 0);
    vi vP(n + 1, 0);
    vi vP1(n + 1, 0);
    vvi pos(200010);
    pos[0 + OS].pb(0);
    for (int i = 0; i < n; ++i) {
      vS[i + 1] = vS[i] + (s[i] == '1' ? 1 : -1);
      vP[i + 1] = vP[i] + (s[i] == '1' ? 1 : 0);
      vP1[i + 1] = vP1[i] + (s[i] == '0' ? 1 : 0);
      pos[vS[i + 1] + OS].pb(i + 1);
    }

    int t0 = vP1[n], t1 = vP[n];
    int maxi = 0;
    for (int r = 1; r <= n; r++) {
      int curS = vS[r];
      int tar0 = curS;
      if (!pos[tar0 + OS].empty()) {
        maxi = max(maxi, r - pos[tar0 + OS][0]);
      }
      int tar1 = curS - 2;
      if (tar1 + OS >= 0 && !pos[tar1 + OS].empty()) {
        for (int i : pos[tar1 + OS]) {
          if (vP1[i] > 0 || (t0 - vP1[r]) > 0) {
            maxi = max(maxi, r - i);
            break;
          }
          if (r - i <= maxi)
            break;
        }
      }
      int tarN = curS + 2;
      if (tarN + OS < 200010 && !pos[tarN + OS].empty()) {
        for (int i : pos[tarN + OS]) {
          if (vP[i] > 0 || (t1 - vP[r]) > 0) {
            maxi = max(maxi, r - i);
            break;
          }
          if (r - i <= maxi)
            break;
        }
      }
    }
    return maxi;
  }
};