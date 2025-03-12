class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int a = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int b = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        return max(a, (int)nums.size() - b);
    }
};