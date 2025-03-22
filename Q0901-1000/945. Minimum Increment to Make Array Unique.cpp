class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int prev = nums[0];
        for(int i = 1;i < nums.size();i++){
           if(nums[i] <= prev){
            count += abs(prev - nums[i]) + 1;
            nums[i] = nums[i] + abs(prev - nums[i])+1;

           }
           prev = nums[i];
        }
      return count;
    }
};