class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = size(nums);
        sort(begin(nums), end(nums));
        nums.erase(unique(begin(nums), end(nums)), end(nums));

        int ans = 0, i = 0;
        for (int j = 0; j < size(nums); ++j)
        {
            while (nums[i] <= nums[j] - n)
                ++i;
            ans = max(ans, j - i + 1);
        }
        return n - ans;
    }
};