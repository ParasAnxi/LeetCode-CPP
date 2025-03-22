class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int maxi = 1;
        int n = nums.size();
        vector<int> dp(n + 1, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    if (maxi < dp[i])
                        maxi = dp[i];
                }
            }
        }
        int temp = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (maxi == dp[i] && (temp % nums[i] == 0 || temp == -1))
            {
                ans.push_back(nums[i]);
                maxi--;
                temp = nums[i];
            }
        }
        return ans;
    }
};