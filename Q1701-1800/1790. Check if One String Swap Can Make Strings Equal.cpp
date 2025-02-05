class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        vector<int> char1(26, 0);
        vector<int> char2(26, 0);
        int n = s1.length();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
                count++;
        }
        for (int i = 0; i < n; i++)
        {
            char1[s1[i] - 'a']++;
        }
        for (int j = 0; j < n; j++)
        {
            char2[s2[j] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (char1[i] != char2[i])
                return false;
        }
        if (count == 2 || count == 0)
            return true;
        else
            return false;
    }
};