class Solution {
public:
  long long findScore(vector<int> &nums) {
    int n = nums.size();
    vector<pair<int, int>> v;
    vector<bool> vis(n, false);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      v.push_back({nums[i], i});
    }
    sort(v.begin(), v.end());
    for (auto [value, index] : v) {
      if (!vis[index]) {
        vis[index] = true;
        if (index - 1 >= 0)
          vis[index - 1] = true;
        if (index + 1 <= n - 1)
          vis[index + 1] = true;
        ans += value;
      } else {
        continue;
      }
    }

    return ans;
  }
};