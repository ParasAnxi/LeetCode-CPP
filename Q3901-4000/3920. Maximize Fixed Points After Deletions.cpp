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
  vi tree;

  void update(int i, int l, int r, int t, int val) {
    if (t < l || r < t) {
      return;
    }
    tree[i] = max(tree[i], val);
    if (l == r) {
      return;
    }
    int mid = (l + r) / 2;
    update(i * 2 + 1, l, mid, t, val);
    update(i * 2 + 2, mid + 1, r, t, val);
  }

  int qry(int i, int l, int r, int t) {
    if (t < l) {
      return 0;
    }
    if (r <= t) {
      return tree[i];
    }
    int mid = (l + r) / 2;
    return max(qry(i * 2 + 1, l, mid, t), qry(i * 2 + 2, mid + 1, r, t));
  }

  int maxFixedPoints(vector<int> &nums) {
    int n = nums.size();
    vpii vI(n);
    for (int i = 0; i < n; i++)
      vI[i] = {nums[i], i};
    sort(vI.begin(), vI.end());
    tree = vi(4 * (1e5 + 1));
    vpii vP(0);
    int prev = 0;
    for (auto [curr, curI] : vI) {
      if (prev != curr) {
        for (auto [dpVal, dpI] : vP) {
          update(0, 0, 1e5 + 1, dpI, dpVal);
        }
        vP.clear();
        prev = curr;
      }
      if (curr > curI)
        continue;
      int newI = curI - curr;
      vP.push_back({qry(0, 0, 1e5 + 1, newI) + 1, newI});
    }
    for (auto [dpVal, dpI] : vP) {
      update(0, 0, 1e5 + 1, dpI, dpVal);
    }
    vP.clear();
    int ans = 0;
    for (auto i : tree) {
      ans = max(ans, i);
    }
    return ans;
  }
};