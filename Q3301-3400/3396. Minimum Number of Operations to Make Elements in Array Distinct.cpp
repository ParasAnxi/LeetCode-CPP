class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int n = nums.size();
    vector<bool> v(100, 0);
    for (int i = n - 1; i >= 0; i--) {
      if (v[nums[i]]){
        return (i + 3) / 3;
      }
      v[nums[i]] = 1;
    }
    return 0;
  }
};