class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> mp;
        for (auto s : arr)
        {
            if (mp.find(s) != mp.end())
            {
                mp[s]++;
            }
            else
            {
                mp[s] = 1;
            }
        }
        int count = 0;
        for (auto s : arr)
        {
            if (mp[s] == 1)
                count++;
            if (count == k)
                return s;
        }
        return "";
    }
};