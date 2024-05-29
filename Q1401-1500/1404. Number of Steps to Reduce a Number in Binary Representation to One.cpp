class Solution
{
public:
    string solve(string s)
    {
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
                break;
            }
            s[i] = '0';
        }
        if (s[0] == '0')
        {
            s = '1' + s;
        }
        return s;
    }

public:
    int numSteps(string s)
    {
        int n = s.size();
        int count = 0;
        while (s != "1")
        {
            if (s.back() == '1')
                s = solve(s);
            else
            {
                s.pop_back();
            }
            count++;
        }
        return count;
    }
};