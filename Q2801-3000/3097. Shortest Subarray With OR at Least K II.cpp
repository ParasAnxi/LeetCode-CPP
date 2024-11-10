class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size(), 
        int mini = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int orr = 0;
            for (int j = i; j < n; j++)
            {
                orr |= nums[j];
                if (orr >= k)
                {
                    mini = min(mini, j - i + 1);
                    break;
                }
            }
        }

        if (mini == INT_MAX)
            return -1;
        else
            return mini;
    }
};