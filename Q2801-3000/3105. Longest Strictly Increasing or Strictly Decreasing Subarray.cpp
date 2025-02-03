class Solution
{
public:
    int solve(vector<int> nums, int start, int end, int n)
    {
        int maxi = 0, count = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i + start] > nums[i + end])
                count++;
            else
            {
                maxi = max(maxi, count);
                count = 1;
            }
        }
        maxi = max(maxi, count);
        return maxi;
    }
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int n = nums.size() - 1;
        int ans = max(solve(nums, 0, 1, n), solve(nums, 1, 0, n));
        return ans;
    }
};