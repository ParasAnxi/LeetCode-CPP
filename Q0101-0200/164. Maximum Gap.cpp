class Solution {
public:
  int maximumGap(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n < 2) {
      return 0;
    }
    int maxi = 0;
    for (int i = n - 1; i > 0; i--) {
      int diff = nums[i] - nums[i - 1];
      if (diff > maxi) {
        maxi = diff;
      }
    }
    return maxi;
  }
};