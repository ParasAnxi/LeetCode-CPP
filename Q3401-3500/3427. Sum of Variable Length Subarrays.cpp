class Solution {
public:
  int subarraySum(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    int i = 0;
    for (int i = 0; i < n; i++) {

      i = max(0, i - nums[i]);

      for (int j = i; j <= i; j++) {
        ans += nums[j];
      }
    }
    return ans;
  }
};