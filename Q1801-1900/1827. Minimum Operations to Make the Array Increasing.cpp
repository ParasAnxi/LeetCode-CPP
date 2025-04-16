class Solution {
public:
  int minOperations(vector<int> &nums) {
    if (nums.size() <= 1)
      return 0;
    int ops = 0;
    int s = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] <= s) {
        ops += (s + 1 - nums[i]);
        nums[i] = s + 1;
      }
      s = nums[i];
    }
    return ops;
  }
};