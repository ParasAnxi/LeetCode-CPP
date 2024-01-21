class Solution
{
public:
    int solve(vector<int> &nums, int n)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return nums[0];
        int ans = 0;
        int include = nums[n] + solve(nums, n - 2);
        int exclude = solve(nums, n - 1);
        ans = max(include, exclude);
        return ans;
    }
    int mem(vector<int> &nums, int n, vector<int> &dp)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return nums[0];
        if (dp[n] != -1)
            return dp[n];
        int inc = nums[n] + mem(nums, n - 2, dp);
        int exc = mem(nums, n - 1, dp);
        return dp[n] = max(inc, exc);
    }
    int so(vector<int> &nums)
    {
        int n = nums.size();
        int prev2 = 0;
        int prev1 = nums[0];
        for (int i = 1; i < n; i++)
        {
            int inc = nums[i] + prev2;
            int exc = prev1;
            int ans = max(inc, exc);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // return solve(nums,n-1);
        // vector<int>dp(n+1,-1);
        // return mem(nums,n-1,dp);
        return so(nums);
    }
};