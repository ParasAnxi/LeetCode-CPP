class Solution {
public:
  long long maximumTripletValue(vector<int> &nums) {
    long long ans = 0, diff = 0,maxi = 0;
    for (long long i = 0; i < nums.size(); i++) {
      ans = max(ans, diff * nums[i]);
      diff = max(diff, maxi - nums[i]);
      maxi = max(maxi, (long long)nums[i]);
    }
    return ans;
  }
};