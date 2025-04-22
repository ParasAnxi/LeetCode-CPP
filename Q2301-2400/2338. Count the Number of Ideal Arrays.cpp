#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvl = vector<vl>;

class Solution {
private:
  const int mod = 1e9 + 7;

  ll pwr(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
      if (b & 1)
        res = (res * a) % m;
      a = (a * a) % m;
      b >>= 1;
    }
    return res;
  }
  vl fact;
  ll facto(ll n) {
    if (n == 0)
      return 1;
    if (fact[n] != -1)
      return fact[n];
    fact[n] = (n * facto(n - 1)) % mod;
    return fact[n];
  }
  ll modX(ll a, ll b) {
    return (((facto(a) * pwr(facto(b), mod - 2, mod)) % mod) *
            pwr(facto(a - b), mod - 2, mod)) %
           mod;
  }

public:
  int idealArrays(int n, int maxi) {
    vvi dp(maxi + 1, vi(15, 0));

    fact.assign(n + 1, -1);

    for (int i = 1; i <= maxi; i++) {
      dp[i][1] = 1;
      for (int j = 2; j * i <= maxi; j++) {
        for (int k = 1; k < min(n, 14); k++) {
          dp[i * j][k + 1] += dp[i][k];
        }
      }
    }

    ll res = 0;
    for (int i = 1; i <= maxi; i++) {
      for (int j = 1; j <= min(n, 14); j++) {
        res = (res + modX(n - 1, n - j) * dp[i][j]) % mod;
      }
    }

    return static_cast<int>(res);
  }
};
