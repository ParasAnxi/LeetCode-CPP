class Solution {
 public:
  vector<int> searchRange(vector<int>& x, int fi) {
    const int y = lower_bound(begin(x), end(x), fi) - begin(x);
    if (y == x.size() || x[y] != fi)
      return {-1, -1};
    const int z = upper_bound(begin(x), end(x), fi) - begin(x) - 1;
    return {y, z};
  }
};

