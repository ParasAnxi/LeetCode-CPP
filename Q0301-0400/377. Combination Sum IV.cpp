class Solution
{
    vector<int> dp;
    int recur(int x, vector<int> &nums)
    {
        if (x < 0)
            return 0;
        if (x == 0)
            return 1;
        int take = 0;
        if (dp[x] != -1)
            return dp[x];
        for (int i = 0; i < nums.size(); i++)
        {
            take += recur(x - nums[i], nums);
        }
        return dp[x] = take;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        dp.resize(target + 1, -1);

        return recur(target, nums);
    }
};