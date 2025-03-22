class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int Mod = 0, ans = 0;

        vector<int> Groups(k);
        Groups[0] = 1;

        for (int num : nums) {
            Mod = (Mod + num % k + k) % k;
            ans += Groups[Mod];
            Groups[Mod]++;
        }
        return ans;
    }
};
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0)
            {
                rem = rem + k;
            }
            if (mp.find(rem) != mp.end())
            {
                ans += mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};