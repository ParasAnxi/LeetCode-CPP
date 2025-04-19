class Solution {
public:
  double minimumAverage(vector<int> &nums) {
    int ans = INT_MAX;
    int n = nums.size() / 2;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      int x = nums[i] + nums[nums.size() - 1 - i];
      ans = min(ans, x);
    }
    return ans / 2.0;
  }
};