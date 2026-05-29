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
  bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
  }
  string sortVowels(string s) {
    unordered_map<char, int> m;
    for (auto ch : s) {
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        m[ch]++;
      }
    }
    vector<pair<char, int>> vP;
    for (auto &p : m) {
      vP.pb(p);
    }
    sort(vP.begin(), vP.end(),
         [](auto &a, auto &b) { return a.second < b.second; });
    stack<char> st;
    for (int i = 0; i < vP.size(); i++) {
      while (vP[i].second--) {
        st.push(vP[i].first);
      }
    }
    for (int i = 0; i < s.size(); i++) {
      if (isVowel(s[i])) {
        char ch = st.top();
        s[i] = ch;
        st.pop();
      }
    }
    return s;
  }
};