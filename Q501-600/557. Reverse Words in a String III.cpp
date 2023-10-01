class Solution
{
public:
    void reverse(int s, int e, string &str)
    {
        while (s <= e)
        {
            swap(str[s], str[e]);
            s++;
            e--;
        }
    }
    string reverseWords(string str)
    {
        int i = 0;
        int n = str.size();
        int s = 0;
        while (i < n)
        {

            if (str[i] == ' ')
            {
                reverse(s, i - 1, str);
                s = i + 1;
            }
            if (i == n - 1)
            {
                reverse(s, i, str);
            }
            i++;
        }
        return str;
    }
};