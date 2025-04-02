class Solution {
public:
  long long maximumTripletValue(vector<int> &nums) {
    int ans = 0;
    int n = nums.size();

    if (n < 3)
      return 0;

    vector<int> lArr(n, 0);
    vector<int> rArr(n, 0);

    int lMaxi = nums[0];
    for (int i = 1; i < n; i++) {
      lMaxi = max(lMaxi, nums[i - 1]);
      lArr[i] = lMaxi;
    }

    int rMaxi = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      rMaxi = max(rMaxi, nums[i + 1]);
      rArr[i] = rMaxi;
    }

    for (int i = 1; i < n - 1; i++) {
      int value = (lArr[i] - nums[i]) * rArr[i];
      ans = max(ans, value);
    }

    return ans;
  }
};