class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0), duplicate = -1;
        for (int i = 0; i < n; i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
            {
                duplicate = abs(nums[i]);
                break;
            }
            nums[index] = -nums[index];
        }
        int missing = (n * (n + 1)) / 2 - (sum - duplicate);
        return vector<int>{duplicate, missing};
    }
};