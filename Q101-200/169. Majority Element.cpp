class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int count = 0;
      int prev = -1;
      for(int i = 0 ;i < nums.size() ; i++){
        if(count == 0) prev = nums[i];
        if(prev == nums[i]) count++;
        else count--;
      }
      return prev;
    }
};