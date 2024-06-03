class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int i = -1;
        int ans = 0;
        for (char ch : t)
        {
            for (i = i + 1; i < s.length(); i++)
            {
                if (ch == s[i])
                {
                    break;
                }
            }
            if (i >= s.length())
            {
                ans++;
            }
        }
        return ans;
    }
};