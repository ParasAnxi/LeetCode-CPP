class Solution
{
public:
    string largestOddNumber(string num)
    {
        int i = num.length() - 1;
        int n = num.length();
        string str = "";
        while (i >= 0)
        {
            char ch = (num[i]);
            if (ch == '0' || ch == '2' || ch == '4' || ch == '6' || ch == '8')
                --i;
            else
            {
                str = num.substr(0, i + 1);
                break;
            }
        }
        if (i < 0)
            return "";
        else
            return str;
    }
};