class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;

        for (auto e : arr)
        {
            int rem = ((e % k) + k) % k;
            mp[rem]++;
        }

        for (auto it : mp)
        {
            int rem = it.first;
            if (rem == 0 && mp[rem] % 2 == 1)
            {
                return 0;
            }
            else if (rem != 0 && mp[rem] != mp[k - rem])
            {
                return 0;
            }
        }
        return 1;
    }
};