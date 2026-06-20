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
  vector<int> minCost(int n, vector<int> &prices, vector<vector<int>> &roads) {
    vector<vector<pair<int, ll>>> adj(n);
    vector<vector<pair<int, ll>>> adj1(n);
    for (auto i : roads) {
      int u = i[0];
      int v = i[1];
      ll w = i[2];
      ll tax = i[3];
      adj[u].pb({v, w});
      adj[v].pb({u, w});
      adj1[u].pb({v, w * tax});
      adj1[v].pb({u, w * tax});
    }
    vi ans(n);
    for (int i = 0; i < n; i++) {
      vll vis(n, 1e18);
      priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                     greater<pair<ll, int>>>
          pq;
      vis[i] = 0;
      pq.push({0, i});
      while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > vis[u])
          continue;
        for (auto i : adj[u]) {
          int v = i.first;
          ll w = i.second;
          if (vis[u] + w < vis[v]) {
            vis[v] = vis[u] + w;
            pq.push({vis[v], v});
          }
        }
      }
      vll vis1(n, 1e18);
      priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                     greater<pair<ll, int>>>
          pq1;
      vis1[i] = 0;
      pq1.push({0, i});
      while (!pq1.empty()) {
        auto [d, u] = pq1.top();
        pq1.pop();
        if (d > vis1[u])
          continue;
        for (auto i : adj1[u]) {
          int v = i.first;
          ll w = i.second;
          if (vis1[u] + w < vis1[v]) {
            vis1[v] = vis1[u] + w;
            pq1.push({vis1[v], v});
          }
        }
      }
      ll mini = 1e18;
      for (int j = 0; j < n; j++) {
        if (vis[j] != 1e18 && vis1[j] != 1e18) {
          ll curr = vis[j] + vis1[j] + prices[j];
          if (curr < mini) {
            mini = curr;
          }
        }
      }
      ans[i] = mini;
    }
    return ans;
  }
};
