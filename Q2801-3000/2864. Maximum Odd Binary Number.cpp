class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int n = s.length();
        int i;
        for (i = n - 1; i >= 0; i--)
        {
            if (i == n - 1 && s[i] == '1')
                break;
            else if (s[i] == '1')
            {
                s[n - 1] = '1';
                s[i] = '0';
                break;
            }
        }
        int left = 0;
        while (s[left] == '1')
        {
            left++;
        }
        for (int right = n - 2; right > left; right--)
        {
            if (s[right] == '1')
            {
                s[right] = '0';
                s[left] = '1';
                while (s[left] == '1')
                {
                    left++;
                }
            }
        }
        return s;
    }
};