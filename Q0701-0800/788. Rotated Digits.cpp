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
  vector<vvi> dp;
  unordered_set<int> ncd{2, 5, 6, 9};
  unordered_set<int> vD{0, 1, 2, 5, 6, 8, 9};
  int countValidNumbers(int idx, string &numStr, int isT, int flg) {
    if (idx == numStr.length()) {
      return flg == 1 ? 1 : 0;
    }
    if (dp[idx][isT][flg] != -1) {
      return dp[idx][isT][flg];
    }
    int ans = 0;
    int limit = isT ? numStr[idx] - '0' : 9;

    for (int digit = 0; digit <= limit; digit++) {
      if (vD.find(digit) == vD.end())
        continue;

      int nC = flg;
      if (ncd.find(digit) != ncd.end()) {
        nC = 1;
      }

      if (digit == numStr[idx] - '0') {
        ans += countValidNumbers(idx + 1, numStr, isT, nC);
      } else {
        ans += countValidNumbers(idx + 1, numStr, 0, nC);
      }
    }

    return dp[idx][isT][flg] = ans;
  }

  int rotatedDigits(int n) {
    string numStr = to_string(n);
    dp = vector<vvi>(numStr.length(), vvi(2, vi(2, -1)));
    return countValidNumbers(0, numStr, 1, 0);
  }
};
