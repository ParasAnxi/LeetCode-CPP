class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int num = *max_element(nums.begin(), nums.end());
        int maxi = 0;
        int count = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxi == nums[i])
                count++;
            else if (maxi < nums[i])
            {
                count = 1;
                maxi = nums[i];
                ans = 1;
            }
            else
            {
                count = 0;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};