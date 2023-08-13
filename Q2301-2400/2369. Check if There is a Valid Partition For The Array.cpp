class Solution{
public:
    bool validPartition(vector<int> &nums){
        vector<bool> dp(nums.size() + 1, false);
        dp[0] = true;
        dp[1] = false;
        dp[2] = (nums[0] == nums[1]);
        for (int i = 3; i <= nums.size(); i++){
            if (nums[i - 1] == nums[i - 2] and dp[i - 2])
            {
                dp[i] = true;
            }
            else if (nums[i - 1] == nums[i - 2] and nums[i - 1] == nums[i - 3] and dp[i - 3])
            {
                dp[i] = true;
            }
            else if (nums[i - 1] == nums[i - 2] + 1 and
                     nums[i - 2] == nums[i - 3] + 1 and dp[i - 3])
            {
                dp[i] = true;
            }
        }
        return dp.back();
    }
};