class Solution {
public:
  int largestInteger(vector<int> &nums, int k) {
    unordered_map<int, int> mp;

    for (int i = 0; i <= nums.size() - k; i++) {
      set<int> s;
      for (int j = i; j < i + k; j++) {
        s.insert(nums[j]);
      }
      for (int num : s) {
        mp[num]++;
      }
    }

    int ans = -1;
    for (auto &[i, count] : mp) {
      if (count == 1) {
        ans = max(ans, i);
      }
    }

    return ans;
  }
};