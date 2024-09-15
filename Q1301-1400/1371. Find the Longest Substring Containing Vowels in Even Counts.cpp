class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int n = s.length();
        unordered_map<char, int> mp;
        vector<char> arr = {'a', 'e', 'i', 'o', 'u'};
        int msk = 1;
        for (char c : arr)
        {
            mp[c] = mask;
            mask = mask * 2;
        }
        mask = 0;
        int ans = 0;
        vector<int> visited(32, -1);
        for (int i = 0; i < n; i++)
        {
            auto it = mp.find(s[i]);
            if (it != mp.end())
                mask ^= it->second;
            else
                mask ^= 0;
            if (visited[mask] == -1 && mask != 0)
                visited[mask] = i;
            ans = max(ans, i - visited[mask]);
        }
        return ans;
    }
};