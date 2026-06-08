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
  int minGenerations(vector<vector<int>> &points, vector<int> &target) {
    set<vi> st;
    for (auto &i : points) {
      st.insert(i);
    }
    if (st.count(target)) {
      return 0;
    }
    if (points.size() == 1) {
      return -1;
    }
    int ans = 0;
    while (!st.count(target)) {
      int n = points.size();
      vvi vT;
      for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
          auto &v1 = points[i];
          auto &v2 = points[j];
          if (v1 == v2) {
            continue;
          }
          int x = (v1[0] + v2[0]) / 2;
          int y = (v1[1] + v2[1]) / 2;
          int z = (v1[2] + v2[2]) / 2;
          if (!st.count({x, y, z})) {
            vT.pb({x, y, z});
          }
        }
      }
      if (vT.size() == 0) {
        return -1;
      }
      for (auto &k : vT) {

        if (!st.count(k)) {
          points.pb(k);
          st.insert(k);
        }
      }
      ans++;
    }
    return ans;
  }
};