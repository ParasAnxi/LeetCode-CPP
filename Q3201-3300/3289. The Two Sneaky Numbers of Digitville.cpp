using umii = unordered_map<int,int>
using vi = vector<int>;
#define pb push_back
class Solution {
public:
  vector<int> getSneakyNumbers(vector<int> &nums) {
    umii mp;
    vi ans;
    for (int i = 0; i < nums.size(); i++) {
      mp[nums[i]]++;
      if (mp[nums[i]] == 2)
        ans.pb(nums[i]);
    }
    return ans;
  }
};