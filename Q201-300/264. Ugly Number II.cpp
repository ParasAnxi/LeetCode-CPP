class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> nums(n);
        nums[0] = 1;
        int x = 0, y = 0, z = 0;

        for (int i = 1; i < n; ++i)
        {
            int temp = min({nums[x] * 2, nums[y] * 3, nums[z] * 5});
            nums[i] = temp;
            if (temp == nums[x] * 2)
                ++x;
            if (temp == nums[y] * 3)
                ++y;
            if (temp == nums[z] * 5)
                ++z;
        }

        return nums[n - 1];
    }
};