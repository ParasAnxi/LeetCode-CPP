class Solution
{
public:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = max(nums[i] - solve(i + 1, j, nums, dp), nums[j] - solve(i, j - 1, nums, dp));
    }
    bool PredictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        if ((solve(0, n - 1, nums, dp)) >= 0)
            return true;
        return false;
    }
};