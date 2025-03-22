class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int ch[26] = {0};
        for (int i = 0; i < s.size(); ++i)
        {
            ch[s[i] - 'a']++;
            ch[t[i] - 'a']--;
        }
        ch[t[s.size()] - 'a']--;
        for (int i = 0; i < 26; ++i)
        {
            if (ch[i] < 0)
            {
                return char('a' + i);
            }
        }
        return 'a';
    }
};