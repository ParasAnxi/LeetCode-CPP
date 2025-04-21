class Solution {
public:
  int countValidSelections(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int x = 0;
    int ans = 0;
    for (auto i : nums) {
      if (i == 0) {
        int y = abs(sum - 2 * x);
        if (y == 0)
          ans += 2;
        else if (y == 1)
          ans++;
      }
      x += i;
    }
    return ans;
  }
};