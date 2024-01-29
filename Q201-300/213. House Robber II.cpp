#define ll long long
class Solution
{
public:
    int so(vector<int> &nums)
    {
        int n = nums.size();
        ll prev2 = 0;
        ll prev1 = nums[0];
        for (int i = 1; i < n; i++)
        {
            ll include = prev2 + nums[i];
            ll exclude = prev1;
            ll ans = max(include, exclude);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    int rob(vector<int> &nums)
    {
        vector<int> first, second;
        if (nums.size() == 1)
            return nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0)
            {
                first.push_back(nums[i]);
            }
            if (i != nums.size() - 1)
            {
                second.push_back(nums[i]);
            }
        }
        return max(so(first), so(second));
    }
};