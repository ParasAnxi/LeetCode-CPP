class Solution {
public:
  int maximumDifference(vector<int> &nums) {
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] < nums[j]) {
          maxi = max(maxi, abs(nums[i] - nums[j]));
        }
      }
    }
    return maxi;
  }
};