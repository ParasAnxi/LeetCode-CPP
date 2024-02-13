class Solution
{
public:
    bool isP(string &st)
    {
        int s = 0;
        int e = st.length() - 1;

        while (s < e)
        {
            if (st[s++] != st[e--])
            {
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string> &words)
    {
        for (auto &s : words)
        {
            if (isP(s))
            {
                return s;
            }
        }
        return "";
    }
};