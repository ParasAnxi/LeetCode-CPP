class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int n = s.length();
        string ans;

        vector<bool> taken(26, false);
        vector<int> lastIndex(26);
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            lastIndex[ch - 'a'] = i;
        }
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            int index = ch - 'a';
            if (taken[index] == true)
            {
                continue;
            }
            while (ans.length() > 0 && ans.back() > ch && lastIndex[ans.back() - 'a'] > i)
            {
                taken[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            taken[index] = true;
        }
        return ans;
    }
};