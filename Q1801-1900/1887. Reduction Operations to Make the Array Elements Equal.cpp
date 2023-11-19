class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int count = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i] != nums[i - 1])
            {
                count += n - i;
            }
        }
        return count;
    }
};