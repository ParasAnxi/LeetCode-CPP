#include <climits>
class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        for (int i = 1; i <= k; i++)
        {
            int mini = INT_MAX;
            int index = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] < mini)
                {
                    mini = nums[j];
                    index = j;
                }
            }
            nums[index] = mini * multiplier;
        }
        return nums;
    }
};