class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int maxi = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
                sum++;
            else
                sum--;
            if (sum == 0)
                maxi = max(maxi, i + 1);
            int rem = sum;
            if (mp.find(sum) != mp.end())
            {
                int len = i - mp[sum];
                maxi = max(maxi, len);
            }
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }
        return maxi;
    }
};