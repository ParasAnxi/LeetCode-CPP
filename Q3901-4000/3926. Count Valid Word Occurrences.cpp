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
  vector<int> countWordOccurrences(vector<string> &chunks,
                                   vector<string> &queries) {
    string st = "";
    for (auto i : chunks) {
      st += i;
    }
    st += " ";
    unordered_map<string, int> mp;
    string sT = "";
    int n = st.length();
    for (int i = 0; i < n; i++) {
      if (st[i] >= 'a' and st[i] <= 'z') {
        sT += st[i];
      } else if ((st[i] == '-' and i > 0 and i < n - 1) &&
                 (st[i - 1] >= 'a' and st[i - 1] <= 'z') &&
                 (st[i + 1] >= 'a' and st[i + 1] <= 'z')) {
        sT += st[i];
      } else {
        if (sT.size()) {
          mp[sT]++;
          sT = "";
        }
      }
    }
    vi ans;
    for (auto i : queries) {
      ans.pb(mp[i]);
    }
    return ans;
  }
};