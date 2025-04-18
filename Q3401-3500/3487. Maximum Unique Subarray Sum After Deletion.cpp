class Solution {
public:
  int maxSum(vector<int> &nums) {
    set<int> s;
    for (auto i : nums)
      if (i > 0) {
        s.insert(i);
      }
    int sum = accumulate(s.begin(), s.end(), 0);
    if (sum > 0) return sum;
    int ans = INT_MIN;
    for (auto i : nums) ans = max(ans, i);
    return ans;
  }
};