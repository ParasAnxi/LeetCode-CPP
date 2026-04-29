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
  bool canPlacePoints(int miniD, int side, int k, vll &vPc) {
    int n = vPc.size();
    for (int i = 0; i < n; ++i) {
      ll s = vPc[i];
      ll e = s + 4LL * side - miniD;
      ll currP = s;
      bool cP = true;
      for (int i = 0; i < k - 1; ++i) {
        int l = 0, h = n - 1;
        while (l < h) {
          int mid = l + (h - l) / 2;
          if (vPc[mid] >= currP + miniD)
            h = mid;
          else
            l = mid + 1;
        }
        if (vPc[l] < currP + miniD || vPc[l] > e) {
          cP = false;
          break;
        }
        currP = vPc[l];
      }

      if (cP)
        return true;
    }

    return false;
  }
  int maxDistance(int side, vector<vector<int>> &points, int k) {
    vll vPc;
    for (auto &i : points) {
      int x = i[0], y = i[1];
      if (x == 0)
        vPc.pb(y);
      else if (y == side)
        vPc.pb(side + x);
      else if (x == side)
        vPc.pb(3LL * side - y);
      else
        vPc.pb(4LL * side - x);
    }
    sort(vPc.begin(), vPc.end());
    int s = 1, e = side;
    while (s < e) {
      int mid = s + (e - s) / 2 + 1;
      if (canPlacePoints(mid, side, k, vPc))
        s = mid;
      else
        e = mid - 1;
    }
    return s;
  }
};