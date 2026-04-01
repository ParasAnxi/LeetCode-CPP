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
  vector<int> survivedRobotsHealths(vector<int> &positions,
                                    vector<int> &healths, string directions) {
    int n = positions.size();
    vector<pair<pii, char>> ans;
    vi res;
    for (int i = 0; i < n; i++) {
      ans.pb({{positions[i], healths[i]}, directions[i]});
    }
    sort(ans.begin(), ans.end());
    stack<pair<pii, char>> st;
    for (int i = 0; i < n; i++) {
      if (st.empty() || st.top().second == 'L' || ans[i].second == 'R') {
        st.push(ans[i]);
      } else {
        while (!st.empty() && st.top().second == 'R' && ans[i].second == 'L') {
          auto p = st.top();
          if (ans[i].first.second > p.first.second) {
            st.pop();
            ans[i].first.second--;
          } else if (ans[i].first.second == p.first.second) {
            st.pop();
            ans[i].first.second = -1;
            break;
          } else {
            st.pop();
            p.first.second--;
            st.push(p);
            ans[i].first.second = -1;
            break;
          }
        }
        if (ans[i].first.second > 0) {
          st.push(ans[i]);
        }
      }
    }

    mii mpF;
    while (!st.empty()) {
      auto p = st.top();
      st.pop();
      mpF[p.first.first] = p.first.second;
    }
    for (int i = 0; i < n; i++) {
      if (mpF.find(positions[i]) != mpF.end()) {
        res.pb(mpF[positions[i]]);
      }
    }
    return res;
  }
};