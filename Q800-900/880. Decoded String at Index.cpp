class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long n = 0;

        for (char &ch : s)
            if (ch >= 'a' && ch <= 'z')
                ++n;
            else
                n *= (ch - '0');
        for (int i = s.size() - 1; i >= 0; --i)
        {
            k %= n;
            if (k == 0 && (s[i] >= 'a' && s[i] <= 'z'))
                return string(1, s[i]);
            if (s[i] > '0' && s[i] <= '9')
                n /= int(s[i] - '0');
            else
                --n;
        }
        return "";
    }
};