class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = 0;
        int ans = 0;
        while (left < n && right < n)
        {
            if (nums[right] - nums[left] <= 2 * k)
            {
                right++;
                ans = max(ans, right - left);
            }
            else
            {
                left++;
                ans = max(ans, right - left);
            }
        }
        return ans;
    }
};