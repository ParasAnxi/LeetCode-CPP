class Solution
{
public:
    string makeFancyString(string s)
    {
        string ans; 
        map<char, int> mp;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (ans.size() >= 2 && ans.back() == ch && ans[ans.size() - 2] == ch)
            {
                continue;
            }

            ans += ch;
            mp[ch]++;
        }

        return ans;
    }
};