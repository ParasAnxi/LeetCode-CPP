class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        vector<long> v(nums.size());
        long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            v[i] = sum;
        }
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (v[i] >= (v[n - 1] - v[i]))
            {
                count++;
            }
        }

        return count;
    }
};