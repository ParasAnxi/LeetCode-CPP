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
  int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration,
                         vector<int> &waterStartTime,
                         vector<int> &waterDuration) {
    int lS = landStartTime.size();
    int wS = waterStartTime.size();
    int ans = INT_MAX;
    for (int i = 0; i < lS; i++) {
      int res = landStartTime[i] + landDuration[i];
      for (int j = 0; j < wS; j++) {
        int wB = max(res, waterStartTime[j]);
        int fT = waterDuration[j] + wB;
        ans = min(ans, fT);
      }
    }
    for (int i = 0; i < wS; i++) {
      int res = waterStartTime[i] + waterDuration[i];
      for (int j = 0; j < lS; j++) {
        int lB = max(res, landStartTime[j]);
        int fT = landDuration[j] + lB;
        ans = min(ans, fT);
      }
    }
    return ans;
  }
};