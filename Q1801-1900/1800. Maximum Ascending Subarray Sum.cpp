class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int n = nums.size();
        int sum = nums[0];
        int maxi = INT_MIN;
        if (n == 1)
        {
            return nums[0];
        }
        maxi = max(sum, maxi);
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
            {
                sum += nums[i];
                maxi = max(sum, maxi);
            }
            else
            {
                sum = nums[i];
                maxi = max(sum, maxi);
            }
        }
        return maxi;
    }
};