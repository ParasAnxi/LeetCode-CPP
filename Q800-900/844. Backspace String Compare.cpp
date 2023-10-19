class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        string result1 = function(s);
        string result2 = function(t);
        return result1 == result2;
    }
    string function(string s)
    {
        string result;
        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '#')
                count++;
            else if (count > 0)
                count--;
            else
            {
                result += s[i];
            }
        }
        return result;
    }
};