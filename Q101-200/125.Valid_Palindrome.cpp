class Solution
{
private:
    string toLC(string s)
    {

        int start = 0;
        int end = s.size() - 1;
        string str = "";

        while (start <= end)
        {
            if (s[start] >= 'a' && s[start] <= 'z' || s[start] >= '0' && s[start] <= '9')
            {
                str += s[start++];
            }
            else if (s[start] >= 'A' && s[start] <= 'Z')
            {
                str += s[start++] - 'A' + 'a';
            }
            else
            {
                start++;
            }
        }
        return str;
    }

public:
    bool isPalindrome(string s)
    {
        string z = toLC(s);
        int st = 0;
        int end = z.size() - 1;
        bool f = true;

        while (st <= end)
        {
            if (z[st] == z[end])
            {
                st++;
                end--;
            }
            else
            {
                f = false;
                break;
            }
        }
        return f;
    }
};
