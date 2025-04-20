class Solution {
public:
  int sumOfGoodNumbers(vector<int> &nums, int k) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      bool flag = true;
      if (i - k >= 0 && nums[i] <= nums[i - k]) {
        flag = false;
      }
      if (i + k < nums.size() && nums[i] <= nums[i + k]) {
        flag = false;
      }
      if (flag) {
        ans += nums[i];
      }
    }
    return ans;
  }
};