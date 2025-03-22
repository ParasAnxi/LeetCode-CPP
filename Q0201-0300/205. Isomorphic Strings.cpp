class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        vector<char> v(100, NULL);
        vector<char> v1(100, NULL);
        for (int i = 0; i < s.length(); i++)
        {
            if (v[s[i] - ' '] != v1[t[i] - ' '])
                return false;
            v[s[i] - ' '] = i + 1;
            v1[t[i] - ' '] = i + 1;
        }
        return true;
    }
};