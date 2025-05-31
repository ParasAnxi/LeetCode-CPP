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
using umii = unordered_map<int, int>;
using umcvi = unordered_map<char, vi>;
using umci = unordered_map<char, int>;
#define pb push_back
#define MOD 1000000007
#define LMOD 1000000000000000007LL
class Solution {
public:
  int nextGreaterElement(int N) {
    string n = to_string(N);
    int i = n.size() - 2;
    while (i >= 0 && n[i] >= n[i + 1]) {
      i--;
    }
    if (i < 0) return -1;
    int j = n.size() - 1;
    while (n[j] <= n[i]) {
      j--;
    }
    swap(n[i], n[j]);
    reverse(n.begin() + i + 1, n.end());
    ll ans = stoll(n);
    return (ans > INT32_MAX) ? -1 : (int)ans;
  }
};