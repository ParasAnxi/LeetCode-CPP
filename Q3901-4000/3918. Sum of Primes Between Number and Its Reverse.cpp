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
  int reverseN(int n) {
    int ans = 0;
    while (n) {
      ans = ans * 10 + n % 10;
      n /= 10;
    }
    return ans;
  }
  int sumOfPrimesInRange(int n) {
    vi vP(1e3 + 1, 1);
    vi vS(1e3 + 1, 0);
    vP[1] = 0;
    for (int i = 2; i <= 1000; i++) {
      if (vP[i] == 1) {
        vS[i] = vS[i - 1] + i;
        int j = i + i;
        while (j <= 1000) {
          vP[j] = 0;
          j += i;
        }
      } else {
        vS[i] = vS[i - 1];
      }
    }
    int rev = reverseN(n);

    int s = min(rev, n);
    int e = max(rev, n);
    int ans = vS[e] - vS[s - 1];
    return ans;
  }
};