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
  unordered_map<int, string> mp;
  int i = 0;
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    string st = "http://tinyurl.com/";
    mp.insert({i, longUrl});
    st = st + to_string(i);
    return st;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    string st = "http://tinyurl.com/";
    string s = shortUrl.substr(st.length());
    int index = stoi(s);
    return mp[index];
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));