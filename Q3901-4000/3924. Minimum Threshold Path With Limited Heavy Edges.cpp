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
  unordered_map<int, vpii> adj;
  void dfs(int source, int k, int mid, vi &vK) {
    if (k <= vK[source])
      return;
    vK[source] = k;
    for (auto &[v, w] : adj[source]) {
      if (w <= mid) {
        dfs(v, k, mid, vK);
      } else {
        if (k > 0) {
          dfs(v, k - 1, mid, vK);
        }
      }
    }
  }
  bool isValid(int n, int source, int target, int k, int mid) {
    vi vK(n, -1);
    dfs(source, k, mid, vK);
    return vK[target] != -1;
  }
  int minimumThreshold(int n, vector<vector<int>> &edges, int source,
                       int target, int k) {
    for (auto &i : edges) {
      int u = i[0];
      int v = i[1];
      int w = i[2];
      adj[u].pb({v, w});
      adj[v].pb({u, w});
    }
    int st = 0, e = 1e9;
    int ans = -1;
    while (st <= e) {
      int mid = st + (e - st) / 2;
      if (isValid(n, source, target, k, mid)) {
        ans = mid;
        e = mid - 1;
      } else
        st = mid + 1;
    }
    return ans;
  }
};