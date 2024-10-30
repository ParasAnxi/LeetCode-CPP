class Solution
{
public:
    int solve(int t, int left, int right, vector<int> &nums, vector<vector<int>> &dp, int c)
    {
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            if (t <= nums[i])
            {
                continue;
            }
            if (ans < dp[i][c] + 1)
            {
                ans = dp[i][c] + 1;
            }
        }

        return ans;
    }
    int minimumMountainRemovals(vector<int> &nums)
    {
        if (nums.size() == 3)
        {
            return 0;
        }
        vector<vector<int>> dp;
        int n = nums.size();
        dp.resize(nums.size(), vector<int>(2, 0));
        int ans = 1000;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            dp[i][0] = solve(nums[i], 0, i - 1, nums, dp, 0);
        }
        for (int i = nums.size() - 2; i >= 1; i--)
        {
            dp[i][1] = solve(nums[i], i + 1, nums.size() - 1, nums, dp, 1);
            if (dp[i][0] && dp[i][1])
            {
                ans = min(ans, n - (dp[i][0] + dp[i][1] + 1));
            }
        }

        return ans;
    }
};