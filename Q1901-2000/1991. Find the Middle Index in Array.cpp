class Solution {
public:
  int findMiddleIndex(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int s = sum;
    int e = 0;
    for (int i = 0; i < nums.size(); i++) {
      e += nums[i];
      if (s == e)
        return i;
      s -= nums[i];
    }
    return -1;
  }
};