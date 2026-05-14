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
  ll power(ll b, ll e) {
    ll ans = 1;
    b %= MOD;
    while (e > 0) {
      if (e % 2 == 1) {
        ans = (ans * b) % MOD;
      }
      b = (b * b) % MOD;
      e /= 2;
    }
    return ans;
  }
  ll modInv(ll n) { return power(n, MOD - 2); }

  ll nCr(int n, int k) {
    if (k < 0 || k > n) {
      return 0;
    }
    if (k == 0 || k == n) {
      return 1;
    }
    if (k > n / 2) {
      k = n - k;
    }
    ll num = 1, d = 1;
    for (int i = 0; i < k; i++) {
      num = (num * (n - i)) % MOD;
      d = (d * (i + 1)) % MOD;
    }
    return (num * modInv(d)) % MOD;
  }
  int countVisiblePeople(int n, int pos, int k) {
    return (nCr(n - 1, k) * 2) % MOD;
  }
};
