class Solution {
public:
  int maxRotateFunction(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    int curr = 0;
    for (int i = 0; i < n; i++) {
      curr += (i * nums[i]);
    }
    int maxi = curr;
    for (int i = 0; i < n; i++) {
      int diff = sum - n * (nums[n - i - 1]);
      curr += diff;
      maxi = max(maxi, curr);
    }
    return maxi;
  }
};