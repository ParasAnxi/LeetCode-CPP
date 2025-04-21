using umii = unordered_map<int, int>;
using vi = vector<int>;
#define pb push_back
class Solution {
public:
  int duplicateNumbersXOR(vector<int> &nums) {
    umii mp;
    for (auto i : nums) mp[i]++;
    int ans = 0;
    for (auto i : mp) {
      if (i.second == 2) ans = ans ^ i.first;
    }
    return ans;
  }
};