class Solution {
public:
  bool increasingTriplet(vector<int> &nums) {
    int n = nums.size();
    int fir = INT_MAX;
    int sec = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (nums[i] < fir) {
        fir = nums[i];
      }
      if (nums[i] < sec && nums[i] > fir) {
        sec = nums[i];
      }
      if (nums[i] > fir && nums[i] > sec) {
        return 1;
      }
    }
    return 0;
  }
};