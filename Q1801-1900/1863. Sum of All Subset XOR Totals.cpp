class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int ans = 0;
        for (auto i : nums)
        {
            ans = ans | i;
        }
        return ans << (nums.size() - 1);
    }
};