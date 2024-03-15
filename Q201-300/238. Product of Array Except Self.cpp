class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int i, n = nums.size();
        vector<int> v1(n, 1), v2(n, 1);
        for (i = 1; i < n; i++)
            v1[i] = v1[i - 1] * nums[i - 1];
        for (i = n - 2; i >= 0; i--)
            v2[i] = v2[i + 1] * nums[i + 1];

        vector<int> ans(n);
        for (i = 0; i < n; i++)
            ans[i] = v1[i] * v2[i];
        return ans;
    }
};