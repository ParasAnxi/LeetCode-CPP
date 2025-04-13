#define ll long long
class Solution {
public:
  int MOD = 1000000007;
  ll solve(ll a, ll b) {
    ll ans = 1;
    while (b) {
      if (b & 1) {
        ans = (ans * a) % MOD;
      }
      a = (a * a) % MOD;
      b /= 2;
    }
    return ans;
  }
  int countGoodNumbers(long long n) {
    return (solve(4, n / 2) * solve(5, n - n / 2)) % MOD;
  }
};