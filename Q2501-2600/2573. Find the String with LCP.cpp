using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ppii = pair<int, pii>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vc = vector<char>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using pis = pair<int, string>;
using vs = vector<string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using umii = unordered_map<int, int>;
#define pb push_back
#define MOD 1000000007
class Solution {
public:
  string findTheString(vector<vector<int>> &lcp) {
    int n = lcp.size();
    string ans(n, 0);
    char ch = 'a';
    for (int i = 0; i < n; ++i) {
      if (lcp[i][i] != n - i)
        return "";
      for (int j = 0; j < i; ++j)
        if (lcp[i][j])
          ans[i] = ans[j];
      if (ans[i])
        continue;
      if (ch > 'z')
        return "";
      ans[i] = ch++;
    }
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        if (lcp[i][j] != lcp[j][i])
          return "";
        if (lcp[i][j]) {
          if (ans[i] != ans[j])
            return "";
          if (j < n - 1) {
            if (lcp[i + 1][j + 1] != lcp[i][j] - 1)
              return "";
          } else if (lcp[i][j] > 1)
            return "";
        } else if (ans[i] == ans[j])
          return "";
      }
    return ans;
  }
};