class Solution {
public:
  int countPartitions(vector<int> &nums) {
    int i, j, cnt = 0;
    for (i = 0; i < nums.size() - 1; i++) {
      int s = 0, e = 0;
      for (j = 0; j < nums.size(); j++) {
        if (j <= i) {
          s += nums[j];
        } else {
          e += nums[j];
        }
      }
      if ((s - e) % 2 == 0) {
        cnt++;
      }
    }
    return cnt;
  }
};