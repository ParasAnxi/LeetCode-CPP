class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int ans = 0;
        long long index = 0;
        long long maxi = 0;
        for (long long i = 1; i <= n; i++)
        {
            while (index < nums.size() && nums[index] <= i)
            {
                maxi += nums[index];
                index++;
            }
            if (maxi < i)
            {
                maxi += i;
                i = maxi;
                ans++;
            }
        }
        return ans;
    }
};