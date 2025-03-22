class Solution
{
public:
    int mod = 1e9 + 7;
    long long solve(vector<int> &nums, unordered_map<int, int> &mp, int in, vector<int> &dp)
    {
        if (dp[in] != -1)
            return dp[in];
        long long ans = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[in] % nums[i] != 0)
                continue;
            int f2 = nums[in] / nums[i];
            if (mp.find(f2) != mp.end())
            {
                ans = (ans + (solve(nums, mp, i, dp) * solve(nums, mp, mp[f2], dp)) % mod) % mod;
            }
        }
        return dp[in] = ans;
    }

    int numFactoredBinaryTrees(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        vector<int> dp(arr.size() + 1, -1);
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]] = i;
        }
        long long ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            ans = (ans + solve(arr, mp, i, dp)) % mod;
        }
        return ans;
    }
};