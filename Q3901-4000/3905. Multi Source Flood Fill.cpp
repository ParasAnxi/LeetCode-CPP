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
  int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<vector<int>> colorGrid(int n, int m, vector<vector<int>> &arr) {
    int k = arr.size();
    queue<pair<int, pii>> q;
    map<pii, int> mp;
    for (int i = 0; i < k; i++) {
      q.push({arr[i][0], {arr[i][1], arr[i][2]}});
      mp[{arr[i][0], arr[i][1]}] = arr[i][2];
    }

    vvi adj(n, vi(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mp.count({i, j}))
          adj[i][j] = mp[{i, j}];
      }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (adj[i][j] != 0)
          vis[i][j] = 1;
      }
    }
    while (!q.empty()) {
      int qN = q.size();
      map<pii, int> curr;
      for (int i = 0; i < qN; i++) {
        auto front = q.front();
        q.pop();
        int x = front.first;
        int y = front.second.first;
        int col = front.second.second;

        for (auto k : dirs) {
          int nX = x + k[0];
          int nY = y + k[1];

          if (nX >= 0 && nY >= 0 && nX < n && nY < m && !vis[nX][nY]) {
            curr[{nX, nY}] = max(curr[{nX, nY}], col);
          }
        }
      }
      for (auto &i : curr) {
        int x = i.first.first;
        int y = i.first.second;
        int col = i.second;

        vis[x][y] = 1;
        adj[x][y] = col;

        q.push({x, {y, col}});
      }
    }

    return adj;
  }
};