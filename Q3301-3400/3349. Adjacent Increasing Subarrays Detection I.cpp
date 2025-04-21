using vi = vector<int>;
class Solution {
public:
  bool hasIncreasingSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    vi v(n, 1);
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) v[i] = v[i + 1] + 1;

      int x = i, y = x + k;
      if (v[x] >= k && y < n && v[y] >= k)
        return 1;
    }
    return 0;
  }
};