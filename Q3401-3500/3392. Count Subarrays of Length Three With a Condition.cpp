class Solution {
public:
  int countSubarrays(vector<int> &nums) {
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
      if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]) {
        cnt++;
      }
    }
    return cnt;
  }
};