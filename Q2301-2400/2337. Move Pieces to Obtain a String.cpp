class Solution
{
public:
    bool canChange(string start, string target)
    {
        if (start.length() != target.length())
        {
            return false;
        }

        int leftStart = 0, rightStart = 0;
        int leftTarget = 0, rightTarget = 0;

        for (char c : start)
        {
            if (c == 'L')
                leftStart++;
            else if (c == 'R')
                rightStart++;
        }

        for (char c : target)
        {
            if (c == 'L')
                leftTarget++;
            else if (c == 'R')
                rightTarget++;
        }

        if (leftStart != leftTarget || rightStart != rightTarget)
        {
            return false;
        }
        int n = start.length();
        int i = 0, j = 0;

        while (i < n || j < n)
        {
            while (i < n && start[i] == '_')
            {
                i++;
            }
            while (j < n && target[j] == '_')
            {
                j++;
            }
            if (i == n && j == n)
            {
                return true;
            }
            if (i == n || j == n)
            {
                return false;
            }
            if (start[i] != target[j])
            {
                return false;
            }
            if (start[i] == 'L')
            {
                if (i < j)
                {
                    return false;
                }
            }
            if (start[i] == 'R')
            {
                if (i > j)
                {
                    return false;
                }
            }
            i++;
            j++;
        }

        return true;
    }
};