class Solution
{
public:
    bool isNumber(string s)
    {
        if (s.empty())
            return false;
        int n = s.size();
        int i = 0;
        bool isNum = false;

        while (i < n && isspace(s[i]))
        {
            i++;
        }
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            i++;
        }

        while (i < n && isdigit(s[i]))
        {
            i++;
            isNum = true;
        }

        if (i < n && s[i] == '.')
        {
            i++;

            while (i < n && isdigit(s[i]))
            {
                i++;
                isNum = true;
            }
        }

        if (isNum && i < n && (s[i] == 'e' || s[i] == 'E'))
        {
            i++;

            if (i < n && (s[i] == '+' || s[i] == '-'))
            {
                i++;
            }

            if (i < n && isdigit(s[i]))
            {
                while (i < n && isdigit(s[i]))
                {
                    i++;
                    isNum = true;
                }
            }
            else
            {
                return false;
            }
        }

        while (i < n && isspace(s[i]))
        {
            i++;
        }
        return isNum && i == n;
    }
};