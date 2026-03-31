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
using umci = unordered_map<char, int>;
#define pb push_back
#define MOD 1000000007
#define LMOD 1000000000000000007LL
class Solution {
public:
  bool chkF(string &s1, string &s2, string &ans) {
    int prev = -1;
    for (int i = s1.size() - 1; i >= 0; i--) {
      if (s1[i] == 'T') {
        if (prev < 0 || i + s2.size() <= prev) {
          copy_n(s2.begin(), s2.size(), ans.begin() + i);
        } else {
          for (int j = prev; j < i + s2.size(); ++j) {
            if (ans[j] != s2[j - i]) {
              return 0;
            }
          }
          copy_n(s2.begin(), prev - i, ans.begin() + i);
        }
        prev = i;
      }
    }
    return 1;
  }
  bool mtc(string &st, char *ans) {
    for (int i = 0; i < st.size(); ++i) {
      if (abs(st[i]) != abs(ans[i]))
        return 0;
    }
    return 1;
  }
  bool chk(const string &s2, char *ans) {
    for (int i = s2.size() - 1; i >= 0; i--) {
      if (ans[i] < 0 && ans[i] > -'z') {
        ans[i]--;
        return 1;
      }
    }
    return 0;
  }
  string generateString(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    string ans(n + m - 1, -'a');
    if (!chkF(str1, str2, ans))
      return "";
    for (int i = 0; i < n; ++i) {
      if (str1[i] == 'F') {
        while (mtc(str2, &ans[i])) {
          if (!chk(str2, &ans[i]))
            return "";
        }
      }
    }
    for (int i = 0; i < ans.size(); ++i) {
      if (ans[i] < 0)
        ans[i] = -ans[i];
    }
    return ans;
  }
};