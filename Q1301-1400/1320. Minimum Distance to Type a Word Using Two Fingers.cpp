using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
using vc = vector<char>;
using mii = map<int, int>;
using mll = map<ll, ll>;
#define pb push_back
#define MOD 1000000007

class Solution {
public:
  int MD(char a, char b) {
    int x1 = (a - 'A') / 6, y1 = (a - 'A') % 6;
    int x2 = (b - 'A') / 6, y2 = (b - 'A') % 6;
    return abs(x1 - x2) + abs(y1 - y2);
  }
  int solve(int i, int s1, int s2,string &word,vvi &vD, vector<vvi> &dp) {
    if (i == word.length()) return 0;
    if (dp[i][s1][s2] != -1) return dp[i][s1][s2];
    int curr = word[i] - 'A';
    int c1 = vD[s1][curr] + solve(i + 1, curr, s2, word, vD, dp);
    int c2 = vD[s2][curr] + solve(i + 1, s1, curr, word, vD, dp);
    return dp[i][s1][s2] = min(c1, c2);
  }
  int minimumDistance(string word) {
    int n = word.length();
    vvi vD(26, vi(26, 0));
    vector<vvi> dp(n + 1, vvi(26, vi(26, -1)));
    for (int i = 0; i < 26; i++) {
      for (int j = i + 1; j < 26; j++) {
        vD[i][j] = vD[j][i] = MD(i + 'A', j + 'A');
      }
    }
    int mini = INT_MAX;
    for (int i = 1; i < n; i++) {
      int s1 = word[0] - 'A';
      int s2 = word[i] - 'A';
      mini = min(mini, solve(0, s1, s2, word, vD, dp));
    }
    return mini;
  }
};