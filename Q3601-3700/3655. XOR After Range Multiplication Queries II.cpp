using ll = long long;
using ull = unsigned long long;
using ld = long double;
using cd = complex<double>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using pll = pair<ll, ll>;
using pci = pair<char, int>;
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
  ll powMod(ll a, ll b, ll m) {
    a %= m;
    ll ans = 1;
    while (b > 0) {
      if (b & 1) {
        ans = (ans * a) % m;
      }
      a = (a * a) % m;
      b >>= 1;
    }
    return ans;
  }

  ll modInv(ll a, ll m) { return powMod(a, m - 2, m); }

  int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    int ans = 0;
    vll vV(n + 1, 1);
    vll vV1(n + 2, 1);
    for (auto i : queries) {
      int u = i[0];
      int v = i[1];
      int k = i[2];
      int vW = i[3];

      if (k == 1) {
        vV[u] = (1LL * vV[u] * vW) % MOD;
        if (v + 1 < n + 1) {
          vV[v + 1] = (vV[v + 1] * modInv(vW, MOD)) % MOD;
        }
      } else if (k == 2) {
        vV1[u] = (1LL * vV1[u] * vW) % MOD;
        if ((v - u) % 2 == 0) {
          if (v + 2 < n + 2) {
            vV1[v + 2] = (vV1[v + 2] * modInv(vW, MOD)) % MOD;
          }
        } else {
          if (v + 1 < n + 2) {
            vV1[v + 1] = (vV1[v + 1] * modInv(vW, MOD)) % MOD;
          }
        }
      } else {
        for (int i = u; i <= v; i += k) {
          nums[i] = (1LL * nums[i] * vW) % MOD;
        }
      }
    }
    for (int i = 2; i < n; i++) {
      vV1[i] = (vV1[i - 2] * vV1[i]) % MOD;
    }
    for (int i = 1; i < n; i++) {
      vV[i] = (vV[i] * vV[i - 1]) % MOD;
    }
    for (int i = 0; i < n; i++) {
      vV[i] = (vV[i] * vV1[i]) % MOD;
    }
    for (int i = 0; i < n; i++) {
      ans = (ans ^ (1LL * vV[i] * nums[i]) % MOD);
    }
    return ans;
  }
};