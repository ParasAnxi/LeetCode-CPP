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
  vector<vector<string>> wordSquares(vector<string> &w) {
    int n = w.size();
    vector<vs> ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          for (int x = 0; x < n; x++) {
            if (i == j || i == k || i == x || j == k || j == x || k == x) {
              continue;
            }
            if (w[i][0] == w[j][0] && w[j][3] == w[x][0] &&
                w[x][3] == w[k][3] && w[k][0] == w[i][3])
              ans.pb({w[i], w[j], w[k], w[x]});
          }
        }
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};