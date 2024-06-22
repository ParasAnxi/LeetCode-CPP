class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                nums[i] = 0;
            }
            else
            {
                nums[i] = 1;
            }
        }
        unordered_map<int, int> mp;
        mp[0] = 1;
        int s = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s += nums[i];
            if (s - k >= 0)
            {
                ans += mp[s - k];
            }

            mp[s]++;
        }

        return ans;
    }
};