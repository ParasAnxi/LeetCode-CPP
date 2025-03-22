class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool isAscending = nums[0] <= nums[nums.size() - 1];
        if (isAscending)
        {
            for (int i = 0; i < nums.size() - 1; i++)
                if (nums[i] > nums[i + 1])
                    return false;
            return true;
        }
        else
        {
            for (int i = 0; i < nums.size() - 1; i++)
                if (nums[i] < nums[i + 1])
                    return false;
            return true;
        }
    }
};