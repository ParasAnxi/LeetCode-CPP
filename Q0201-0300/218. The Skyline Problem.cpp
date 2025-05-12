class Solution {
public:
  static bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first != b.first)
      return a.first < b.first;
    return a.second > b.second;
  }
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    vector<pair<int, int>> vH;
    for (auto &i : buildings) {
      vH.push_back({i[0], i[2]});
      vH.push_back({i[1], -i[2]});
    }
    sort(vH.begin(), vH.end(), cmp);
    map<int, int> mp;
    mp[0] = 1;
    int maxi = 0;
    vector<vector<int>> ans;
    for (auto &i : vH) {
      int x = i.first, height = i.second;
      if (height >= 0) {
        mp[height]++;
        if (height > maxi) {
          maxi = height;
          ans.push_back({x, height});
        }
      } else {
        height = -height;
        mp[height]--;
        if (mp[height] == 0)
          mp.erase(height);
        int nMaxi = mp.rbegin()->first;
        if (nMaxi != maxi) {
          maxi = nMaxi;
          ans.push_back({x, nMaxi});
        }
      }
    }
    return ans;
  }
};