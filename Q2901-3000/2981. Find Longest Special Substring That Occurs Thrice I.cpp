class Solution
{
public:
    bool isSpecial(string &s, int n)
    {
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                return false;
            }
        }
        return true;
    }
    int maximumLength(string s)
    {
        unordered_map<string, int> mp;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 1; j < s.length() - i + 1; j++)
            {
                mp[s.substr(i, j)]++;
            }
        }
        int maxLengthSubstring = -1;
        for (auto it : mp)
        {
            if (it.second >= 3)
            {
                string subStr = it.first;
                int currSubstrLength = subStr.length();
                bool kunal = isSpecial(subStr, currSubstrLength);
                if (kunal == true)
                {
                    maxLengthSubstring = max(maxLengthSubstring, currSubstrLength);
                }
            }
        }
        return maxLengthSubstring;
    }
};