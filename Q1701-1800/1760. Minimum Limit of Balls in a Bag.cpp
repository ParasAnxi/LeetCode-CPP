class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int ans = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] >= mid)
                {
                    ans += (nums[i] - 1) / mid;
                }
            }
            if (ans > maxOperations)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r + 1;
    }
};