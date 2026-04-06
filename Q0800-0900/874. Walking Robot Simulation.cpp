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
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    pii dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int idx = 0;
    int x = 0, y = 0;
    int ans = 0;

    set<pii> st;
    for (auto &it : obstacles) {
      st.insert({it[0], it[1]});
    }
    for (auto it : commands) {
      if (it == -1) {
        idx = (idx + 1) % 4;
      } else if (it == -2) {
        idx = (idx + 3) % 4;
      }

      else {
        int dX = dir[idx].first;
        int dY = dir[idx].second;
        for (int i = 0; i < it; i++) {
          if (st.find({x + dX, y + dY}) == st.end()) {
            x = x + dX;
            y = y + dY;
          } else {
            break;
          }
        }
        ans = max(ans, x * x + y * y);
      }
    }
    return ans;
  }
};