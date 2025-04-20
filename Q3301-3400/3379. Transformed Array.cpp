using vi = vector<int>;
#define pb push_back
class Solution {
public:
  vector<int> constructTransformedArray(vector<int> &nums) {
    int n = nums.size();
    vi ans;
    for (int i = 0; i < n; i++) {
      int ind = (i + nums[i]) % n;
      if (ind < 0) {
        ind = ind + n;
      }
      ans.pb(nums[ind]);
    }

    return ans;
  }
};