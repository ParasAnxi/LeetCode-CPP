class Solution {
public:

    int jump(vector<int>& nums) {

      for(int i = 1; i < nums.size(); i++)
      {
        nums[i] = max(nums[i] + i, nums[i-1]);
      }

      int i = 0;
      int ans = 0;

      while(i < nums.size() - 1)
      {
        ans++;
        i = nums[i];
      }

      return ans;
    }
};