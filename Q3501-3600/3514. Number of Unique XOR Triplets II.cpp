class Solution {
public:
  int uniqueXorTriplets(vector<int> &nums) {
    unordered_set<int> s1;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        s1.insert(nums[i] ^ nums[j]);
      }
    }
    unordered_set<int> s2;
    for (int k = 0; k < n; k++) {
      for (auto it : s1) {
        s2.insert(nums[k] ^ it);
      }
    }
    return s2.size();
  }
};