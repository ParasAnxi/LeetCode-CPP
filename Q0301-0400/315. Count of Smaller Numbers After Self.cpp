class FTree {
public:
  vector<int> bit;
  FTree(int n) { bit.resize(n, 0); }
  void add(int i, int x) {
    i++;
    while (i < bit.size()) {
      bit[i] += x;
      i += (i & -i);
    }
  }
  void up(int i, int x) { add(i, x); }

  int qry(int i) {
    i++;
    int ans = 0;
    while (i > 0) {
      ans += bit[i];
      i -= (i & -i);
    }
    return ans;
  }
};
class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    FTree bit(20005);
    vector<int> ans(nums.size(), 0);
    for (int i = nums.size() - 1; i >= 0; i--) {
      int sft = nums[i] + 10001;
      ans[i] = bit.qry(sft - 1);
      bit.up(sft, 1);
    }
    return ans;
  }
};