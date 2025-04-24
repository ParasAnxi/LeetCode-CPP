class Solution {
public:
  int countCompleteSubarrays(vector<int> &nums) {
    int n = nums.size();
    unordered_set<int> st1(nums.begin(), nums.end());
    int count = 0;
    for (int i = 0; i < n; i++) {
      unordered_set<int> st2;
      for (int j = i; j < n; j++) {
        st2.insert(nums[j]);
        if (st2.size() == st1.size()) {
          count++;
        }
      }
    }
    return count;
  }
};