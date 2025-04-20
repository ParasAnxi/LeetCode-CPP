using vi = vector<int>;
#define pb push_back
class Solution {
public:
  vi build(vi &nums) {
    vi tree = {nums[0]};
    const int size = nums.size();
    for (int i = 0; i < size; i++) {
      tree.pb(nums[i] + tree[tree.size() - 1]);
    }
    return tree;
  }
  int subarraySum(vector<int> &nums) {
    int ans = 0;
    vi tree = build(nums);
    const int size = nums.size();
    for (int i = 0; i < size; i++) {
      int start = max(0, i - nums[i]);
      ans += tree[i] - tree[start] + nums[i];
    }
    return ans;
  }
};