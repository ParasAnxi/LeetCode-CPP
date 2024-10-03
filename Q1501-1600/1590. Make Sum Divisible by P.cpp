class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0LL) % p;
        if (sum == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;
        int prefix = 0;
        int mini = n;

        for (int i = 0; i < n; ++i)
        {
            prefix = (prefix + nums[i]) % p;
            int target = (prefix - sum + p) % p;

            if (mp.find(target) != mp.end())
            {
                mini = min(mini, i - mp[target]);
            }

            mp[prefix] = i;
        }

        return (mini == n) ? -1 : mini;
    }
};