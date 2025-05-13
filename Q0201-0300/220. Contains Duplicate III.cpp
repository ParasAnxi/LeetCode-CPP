class segTree {
  vector<int> tree;
  int n;

public:
  segTree(int sz) {
    this->n = sz;
    tree.assign(2 * n, INT_MIN);
  }
  void update(int pB, int x) {
    pB += n;
    tree[pB] = max(tree[pB], x);
    for (; pB >>= 1;)
      tree[pB] = max(tree[2 * pB], tree[2 * pB + 1]);
  }
  int qry(int x, int y) {
    y = min(y, n - 1);
    x = max(0, x);
    int ans = INT_MIN;
    for (x += n, y += n + 1; x < y; x >>= 1, y >>= 1) {
      if (x & 1)
        ans = max(ans, tree[x++]);
      if (y & 1)
        ans = max(tree[--y], ans);
    }
    return ans;
  }
};
class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff,
                                     int valueDiff) {
    int n = nums.size();
    auto newN = nums;
    sort(newN.begin(), newN.end());
    segTree t(n);
    for (int i = 0; i < n; i++) {
      int pB = lower_bound(newN.begin(), newN.end(), nums[i]) - newN.begin();
      int uB = upper_bound(newN.begin(), newN.end(), nums[i] + valueDiff) -
               newN.begin() - 1;
      int lB = lower_bound(newN.begin(), newN.end(), nums[i] - valueDiff) -
               newN.begin();
      int z = t.qry(lB, uB);
      if (z != INT_MIN && i - z <= indexDiff)
        return 1;
      t.update(pB, i);
    }
    return 0;
  }
};