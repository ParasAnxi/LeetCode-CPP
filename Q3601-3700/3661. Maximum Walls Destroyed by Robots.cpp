using ll = long long;
using ull = unsigned long long;
using ld = long double;
using cd = complex<double>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using pll = pair<ll, ll>;
using pci = pair<char, int>;
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
  int solveBnd(int l, int r, vi &walls) {
    if (l > r)
      return 0;
    auto it1 = upper_bound(walls.begin(), walls.end(), r);
    auto it2 = lower_bound(walls.begin(), walls.end(), l);
    return (int)(it1 - it2);
  }

  int solveRec(int i, int dir, vpii &vR, vpii &vRng, vector<int> &walls) {
    if (i < 0)
      return 0;
    if (i == 0) {
      if (dir == 0) {
        return solveBnd(vRng[0].first, vR[0].first, walls);
      } else {
        return solveBnd(vR[0].first, vRng[0].second, walls);
      }
    }
    if (dir == 1) {
      int prevB = max(solveRec(i - 1, 0, vR, vRng, walls),
                      solveRec(i - 1, 1, vR, vRng, walls));
      return prevB + solveBnd(vR[i].first, vRng[i].second, walls);
    } else {
      int op1 = solveRec(i - 1, 0, vR, vRng, walls) +
                solveBnd(vRng[i].first, vR[i].first, walls);
      int oL = solveBnd(max(vRng[i].first, vR[i - 1].first),
                        min(vR[i].first, vRng[i - 1].second), walls);
      int op2 = solveRec(i - 1, 1, vR, vRng, walls) +
                solveBnd(vRng[i].first, vR[i].first, walls) - oL;
      return max(op1, op2);
    }
  }

  int solveMemo(int i, int dir, vpii &vR, vpii &vRng, vvi &dp, vi &walls) {
    if (i < 0)
      return 0;
    if (dp[i][dir] != -1)
      return dp[i][dir];

    if (i == 0) {
      if (dir == 0) {
        return dp[i][dir] = solveBnd(vRng[0].first, vR[0].first, walls);
      } else {
        return dp[i][dir] = solveBnd(vR[0].first, vRng[0].second, walls);
      }
    }

    if (dir == 1) {
      int prevB = max(solveMemo(i - 1, 0, vR, vRng, dp, walls),
                      solveMemo(i - 1, 1, vR, vRng, dp, walls));
      return dp[i][dir] = prevB + solveBnd(vR[i].first, vRng[i].second, walls);
    } else {
      int op1 = solveMemo(i - 1, 0, vR, vRng, dp, walls) +
                solveBnd(vRng[i].first, vR[i].first, walls);
      int oL = solveBnd(max(vRng[i].first, vR[i - 1].first),
                        min(vR[i].first, vRng[i - 1].second), walls);
      int op2 = solveMemo(i - 1, 1, vR, vRng, dp, walls) +
                solveBnd(vRng[i].first, vR[i].first, walls) - oL;
      return dp[i][dir] = max(op1, op2);
    }
  }

  int solveTab(vi &robots, vi &distance, vi &walls) {
    int n = robots.size();
    vpii vR;
    for (int i = 0; i < n; i++) {
      vR.pb({robots[i], distance[i]});
    }
    sort(walls.begin(), walls.end());
    sort(vR.begin(), vR.end());
    vpii vRng;
    for (int i = 0; i < n; i++) {
      ll pos = vR[i].first, dis = vR[i].second;
      ll lR = (i == 0) ? INT_MIN : (ll)vR[i - 1].first + 1;
      ll rR = (i == n - 1) ? INT_MAX : (ll)vR[i + 1].first - 1;
      ll l = max(lR, pos - dis), r = min(rR, pos + dis);
      vRng.pb({l, r});
    }
    vvi dp(n, vi(2, 0));
    dp[0][0] = solveBnd(vRng[0].first, vR[0].first, walls);
    dp[0][1] = solveBnd(vR[0].first, vRng[0].second, walls);

    for (int i = 1; i < n; i++) {
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) +
                 solveBnd(vR[i].first, vRng[i].second, walls);
      int op1 = dp[i - 1][0] + solveBnd(vRng[i].first, vR[i].first, walls);
      int oL = solveBnd(max(vRng[i].first, vR[i - 1].first),
                        min(vR[i].first, vRng[i - 1].second), walls);
      int op2 = dp[i - 1][1] + solveBnd(vRng[i].first, vR[i].first, walls) - oL;
      dp[i][0] = max(op1, op2);
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
  }

  int solveSo(vi &robots, vi &distance, vi &walls) {
    int n = robots.size();
    vpii vR;
    for (int i = 0; i < n; i++) {
      vR.pb({robots[i], distance[i]});
    }
    sort(walls.begin(), walls.end());
    sort(vR.begin(), vR.end());
    vpii vRng;
    for (int i = 0; i < n; i++) {
      ll pos = vR[i].first, dis = vR[i].second;
      ll lR = (i == 0) ? INT_MIN : (ll)vR[i - 1].first + 1;
      ll rR = (i == n - 1) ? INT_MAX : (ll)vR[i + 1].first - 1;
      ll l = max(lR, pos - dis), r = min(rR, pos + dis);
      vRng.pb({l, r});
    }

    vi prev(2, 0), curr(2, 0);
    prev[0] = solveBnd(vRng[0].first, vR[0].first, walls);
    prev[1] = solveBnd(vR[0].first, vRng[0].second, walls);

    for (int i = 1; i < n; i++) {
      curr[1] =
          max(prev[0], prev[1]) + solveBnd(vR[i].first, vRng[i].second, walls);
      int op1 = prev[0] + solveBnd(vRng[i].first, vR[i].first, walls);
      int oL = solveBnd(max(vRng[i].first, vR[i - 1].first),
                        min(vR[i].first, vRng[i - 1].second), walls);
      int op2 = prev[1] + solveBnd(vRng[i].first, vR[i].first, walls) - oL;
      curr[0] = max(op1, op2);
      prev = curr;
    }

    return max(prev[0], prev[1]);
  }

  int maxWalls(vector<int> &robots, vector<int> &distance, vector<int> &walls) {
    // int n = robots.size();
    // vpii vR;
    // for (int i = 0; i < n; i++) {
    //   vR.pb({robots[i], distance[i]});
    // }
    // sort(walls.begin(), walls.end());
    // sort(vR.begin(), vR.end());
    // vpii vRng;
    // for (int i = 0; i < n; i++) {
    //   ll pos = vR[i].first;
    //   ll dis = vR[i].second;
    //   ll lR = (i == 0) ? INT_MIN : (ll)vR[i - 1].first + 1;
    //   ll rR = (i == n - 1) ? INT_MAX : (ll)vR[i + 1].first - 1;
    //   ll l = max(lR, pos - dis);
    //   ll r = min(rR, pos + dis);
    //   vRng.pb({l, r});
    // }
    // return max(solveRec(n - 1, 0, vR, vRng, walls), solveRec(n - 1, 1, vR,
    // vRng, walls)); vvi dp(n, vi(2, -1)); return max(solveMemo(n - 1, 0, vR,
    // vRng, dp, walls), solveMemo(n - 1, 1, vR, vRng, dp, walls));
    return solveSo(robots, distance, walls);
  }
};
