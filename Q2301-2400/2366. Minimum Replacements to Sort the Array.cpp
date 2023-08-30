class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        long long ans = 0, n = nums[nums.size() - 1], p;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] > n)
            {
                p = ceil(nums[i] / (double)n);
                n = nums[i] / p;
                ans += p - 1;
            }
            else
            {
                n = nums[i];
            }
        }
        return ans;
    }
};