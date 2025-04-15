class Solution {
public:
  int solve(int x) {
    if (x <= 1)
      return 1;
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x++;
    return x;
  }
  int uniqueXorTriplets(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;
    return solve(n + 1);
  }
};