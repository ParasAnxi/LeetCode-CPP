class Solution {
public:
  int minElement(vector<int> &nums) {
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      int j = nums[i];
      int sum = 0;
      while (j > 0) {
        sum += j % 10;
        j /= 10;
      }
      if (sum < ans) ans = sum;
    }
    return ans;
  }
};