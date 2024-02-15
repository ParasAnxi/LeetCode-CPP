class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        vector<long long> temp;
        for (long long i = nums.size() - 1; i >= 0; i--)
        {
            sum += nums[i];
            temp.push_back(nums[i]);
        }

        long long index;
        for (long long i = 0; i < nums.size(); i++)
        {
            long long diff = sum - temp[i];

            if (temp[i] >= diff)
                sum = diff;

            else
            {
                index = i;
                break;
            }
        }

        if (nums.size() - index < 3)
            return -1;

        return sum;
    }
};