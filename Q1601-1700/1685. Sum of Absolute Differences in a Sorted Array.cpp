class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        vector<int> ans;
        int sum = 0, cur = 0, n = nums.size(), i;
        for (auto &it : nums)
            sum += it;
        for (i = 0; i < n; i++)
        {
            cur += nums[i];
            int s = ((nums[i] * (i + 1)) - cur);
            int e = (sum - cur) - (nums[i] * (n - (i + 1)));
            ans.push_back(s + e);
        }
        return ans;
    }
};