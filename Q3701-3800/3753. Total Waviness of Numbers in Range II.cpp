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
  string st;
  ll dp[18][11][11][2][2][2];
  bool vis[18][11][11][2][2];

  pair<ll, ll> solve(int idx, int x, int y, bool tight, bool z) {
    if (idx == st.size()) {
      return {1, 0};
    }
    if (vis[idx][x][y][tight][z]) {
      return {dp[idx][x][y][tight][z][0], dp[idx][x][y][tight][z][1]};
    }
    vis[idx][x][y][tight][z] = true;
    ll count = 0;
    ll wV = 0;

    int limit = tight ? st[idx] - '0' : 9;

    for (int i = 0; i <= limit; i++) {
      bool nT = tight && (i == limit);
      bool nZ = z && (i == 0);

      int np = nZ ? 10 : i;
      int npp = nZ ? 10 : (z ? 10 : y);

      bool wX = false;
      if (x != 10 && y != 10) {
        if ((x < y && y > i) || (x > y && y < i)) {
          wX = true;
        }
      }
      auto [c, w] = solve(idx + 1, npp, np, nT, nZ);
      count += c;
      wV += w + (wX ? c : 0);
    }
    dp[idx][x][y][tight][z][0] = count;
    dp[idx][x][y][tight][z][1] = wV;
    return {count, wV};
  }

  ll solveF(ll n) {
    if (n < 100) {
      return 0;
    }
    st = to_string(n);
    memset(vis, 0, sizeof(vis));
    return solve(0, 10, 10, 1, 1).second;
  }

  long long totalWaviness(long long num1, long long num2) {
    return solveF(num2) - solveF(num1 - 1);
  }
};