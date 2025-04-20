class Solution {
public:
  int minimumSumSubarray(vector<int> &nums, int l, int r) {
    int n = nums.size();
    int ans = INT_MAX;
    bool flag = false;
    for (int k = l; k <= r; k++) {
      int i = 0, j = 0, res = 0;
      while (j < n) {
        res += nums[j];
        if (j - i + 1 == k) {
          if (res > 0) {
            ans = min(ans, res);
            flag = true;
          }
          res -= nums[i];
          i++;
        }
        j++;
      }
    }
    return !flag ? -1 : ans;
  }
};