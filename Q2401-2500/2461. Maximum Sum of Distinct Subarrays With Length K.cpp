class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        long long sum = 0;
        for (int i = 0; i < k; i++)
            mp[nums[i]]++, sum += nums[i];
        long long ans = 0;
        if (mp.size() == k)
            ans = sum;

        for (auto i = k; i < nums.size(); i++)
        {
            sum -= nums[i - k];
            sum += nums[i];
            mp[nums[i]]++;
            if (mp[nums[i - k]] == 1)
                mp.erase(nums[i - k]);
            else
                mp[nums[i - k]]--;
            if (mp.size() == k)
                ans = max(sum, ans);
        }
        return ans;
    }
};