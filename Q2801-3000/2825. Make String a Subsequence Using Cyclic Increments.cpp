class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        char *nxt = &str2[0];
        for (char c : str1)
        {
            if (c == *nxt || (c == 'z' ? 'a' : (c + 1)) == *nxt)
            {
                nxt++;
                if (*nxt == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};