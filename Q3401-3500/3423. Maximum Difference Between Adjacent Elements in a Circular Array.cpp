#define pb push_back
class Solution {
public:
  int maxAdjacentDistance(vector<int> &nums) {
    nums.pb(nums[0]);
    int n = nums.size();
    int diff = 0;
    for (int i = 0; i < n - 1; i++) {
      int ans = abs(nums[i] - nums[i + 1]);
      if (ans > diff) {
        diff = ans;
      }
    }
    return diff;
  }
};