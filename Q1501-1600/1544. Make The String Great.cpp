class Solution
{
public:
    string makeGood(string s)
    {
        int i = 0;
        int n = s.length();

        while (i < n - 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (abs(s[i] - s[i + 1]) == 32)
                {
                    s.erase(i, 2);
                }
            }
            i++;
        }
        return s;
    }
};