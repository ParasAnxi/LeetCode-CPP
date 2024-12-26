class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum < abs(target) || (totalSum + target) % 2 != 0)
            return 0;
        int sum = (totalSum + target) / 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int num : nums)
        {
            for (int j = sum; j >= num; j--)
            {
                dp[j] += dp[j - num];
            }
        }
        return dp[sum];
    }
};