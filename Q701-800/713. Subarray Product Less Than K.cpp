class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int count = 0;
        int mul = 1;
        int i = 0;
        int j = 0;
        if (k <= 1)
        {
            return 0;
        }
        while (j < nums.size())
        {
            mul = mul * nums[j];
            while (mul >= k)
            {
                mul = mul / nums[i];
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
};