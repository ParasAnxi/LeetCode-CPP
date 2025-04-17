class Solution {
public:
  int countPairs(vector<int> &nums, int k) {
    int n = nums.size();
    int s = 0;
    int count = 0;
    while (s < n) {
      for (int i = s + 1; i < n; i++) {
        if (nums[s] == nums[i] && (s * i) % k == 0) {
          count++;
        }
      }
      s++;
    }
    return count;
  }
};