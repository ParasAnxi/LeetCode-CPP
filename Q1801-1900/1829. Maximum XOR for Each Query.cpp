class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int k = 1 << (maximumBit - 1);
        k = k | (k - 1);
        int curr = 0, n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            curr ^= nums[i];
            ans[n - i - 1] = (k ^ curr);
        }
        return ans;
    }
};