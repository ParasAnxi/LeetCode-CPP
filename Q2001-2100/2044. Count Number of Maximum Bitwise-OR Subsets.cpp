class Solution
{
public:
    void solve(int &ans, vector<int> &nums, int &maxi, int i, int bits)
    {

        if (i >= nums.size())
        {
            if (bits == maxi)
            {
                ans++;
            }
            return;
        }
        solve(ans, nums, maxi, i + 1, bits);
        solve(ans, nums, maxi, i + 1, bits | nums[i]);
    };
    int countMaxOrSubsets(vector<int> &nums)
    {
        int maxi = 0;
        for (int num : nums)
        {
            maxi |= num;
        }

        int ans = 0;
        solve(ans, nums, maxi, 0, 0);
        return ans;
    }
};