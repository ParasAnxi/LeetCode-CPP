class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {

        int n = spaces.size() - 1;
        int size = s.length();

        for (int i = 0; i <= n; i++)
        {
            s += " ";
        }

        int i = size + n, j = size - 1, index = n;

        while (j >= 0 && index >= 0)
        {
            if (j != spaces[index] - 1)
            {
                s[i] = s[j];
                i--, j--;
            }
            else
            {
                s[i] = ' ';
                i--;
                index--;
            }
        }

        if (spaces[0] == 0)
            s[0] = ' ';
        return s;
    }
};