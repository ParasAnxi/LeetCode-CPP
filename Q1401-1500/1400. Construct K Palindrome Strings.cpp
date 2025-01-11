class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        map<int, int> mp;
        int m = k;
        for (char c : s)
        {
            mp[c]++;
        }
        for (int i = 'a'; i <= 'z'; i++)
        {
            if (mp[i] % 2)
            {
                k--;
                mp[i]--;
            }
            if (k < 0)
                return 0;
        }

        for (int i = 'a'; i <= 'z'; i++)
        {
            k -= mp[i];
        }
        return k <= 0;

    }
};