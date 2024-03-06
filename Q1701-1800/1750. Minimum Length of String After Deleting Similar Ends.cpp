class Solution
{
public:
    int checkRepeatI(int i, string str, int n)
    {
        while (i + 1 < n && str[i] == str[i + 1])
        {
            i++;
        }
        return i;
    }

    int checkRepeatJ(int j, string str, int i)
    {
        while (j > i && str[j] == str[j - 1] && j > 0)
        {
            j--;
        }
        return j;
    }

    int minimumLength(string str)
    {
        int i = 0;
        int n = str.size();
        int j = n - 1;

        while (i < j)
        {
            if (str[i] != str[j])
            {
                break;
            }
            else
            {
                i = checkRepeatI(i, str, n);
                i++;
                if (j > i)
                {
                    j = checkRepeatJ(j, str, i);
                    j--;
                }
            }
        }
        return j - i + 1;
    }
};