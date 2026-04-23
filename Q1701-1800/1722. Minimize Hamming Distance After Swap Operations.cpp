using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
using mii = map<int, int>;
using msi = unordered_map<string, int>;
using uss = unordered_set<string>;
using mll = map<ll, ll>;
#define pb push_back

class DJS {
  vi parent;
  vi rank;

public:
  DJS(int n) {
    rank.resize(n, 0);
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int find(int x) { return parent[x] == x ? x : find(parent[x]); }

  void join(int u, int v) {
    int pX = find(u);
    int pY = find(v);
    if (pX != pY) {
      if (rank[pX] < rank[pY]) {
        parent[pX] = pY;
      } else if (rank[pY] < rank[pX]) {
        parent[pY] = pX;
      } else {
        parent[pY] = pX;
        rank[pX]++;
      }
    }
  }
};
class Solution {
public:
  int minimumHammingDistance(vector<int> &source, vector<int> &target,
                             vector<vector<int>> &allowedSwaps) {
    int n = source.size();
    DJS djs(n);
    for (int i = 0; i < allowedSwaps.size(); i++) {
      djs.join(allowedSwaps[i][0], allowedSwaps[i][1]);
    }
    int ans = 0;
    unordered_map<int, unordered_map<int, int>> mp;
    for (int i = 0; i < n; i++) {
      int x = djs.find(i);
      mp[x][source[i]]++;
    }
    for (int i = 0; i < n; i++) {
      int x = djs.find(i);
      if (mp[x][target[i]]) {
        mp[x][target[i]]--;
      } else {
        ans++;
      }
    }
    return ans;
  }
};