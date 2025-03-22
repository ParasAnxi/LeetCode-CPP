class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        for (auto i : nums)
            mp[i]++;
        for (auto i : mp)
        {
            if (i.second == 1)
                return -1;
            if (i.second % 3 == 0)
                ans += i.second / 3;
            else
                ans += i.second / 3 + 1;
        }
        return ans;
    }
};