class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    unordered_map<int, bool> mp;
    for (auto i : nums) {
      if (i < k) {
        return -1;
      }
      if (i != k) {
        mp[i] = true;
      }
    }
    return mp.size();
  }
};