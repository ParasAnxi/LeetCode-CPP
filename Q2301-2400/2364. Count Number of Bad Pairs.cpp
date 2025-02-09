class Solution
{
public:
    long countBadPairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        long good = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int key = nums[i] - i;
            good += mp[key];
            mp[key]++;
        }

        long total = static_cast<long>(nums.size()) * (nums.size() - 1) / 2;
        return total - good;
    }
};