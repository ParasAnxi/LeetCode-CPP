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
  pii solve(string s) {
    int k = 0;
    string r = "";
    string i = "";
    while (s[k] != '+') {
      r += s[k];
      k++;
    }
    for (int j = k + 1; j < s.length() - 1; j++) {
      i += s[j];
    }
    int real = stoi(r);
    int img = stoi(i);
    return {real, img};
  }
  string complexNumberMultiply(string num1, string num2) {
    pii pR = solve(num1);
    pii pI = solve(num2);
    string real = to_string((pR.first * pI.first - pR.second * pI.second));
    string img = to_string(pR.first * pI.second + pI.first * pR.second);
    string ans = real + "+" + img + "i";
    return ans;
  }
};