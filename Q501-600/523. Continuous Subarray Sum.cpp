class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int i = 0;
        int sum = 0;
        mp[0] = 0;
        while (i < nums.size())
        {
            sum += nums[i];
            if (mp.find(sum % k) == mp.end())
            {
                mp[sum % k] = i + 1;
            }
            else
            {
                if (i - mp[sum % k] + 1 >= 2)
                    return 1;
            }
            i++;
        }
        return 0;
    }
};