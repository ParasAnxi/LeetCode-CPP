class Solution
{
public:
    int minimumLength(string s)
    {
        int n = s.length();
        int count[26];
        for (const char &c : s)
        {
            count[c - 'a']++;
        }
        for (int freq : count)
        {
            n -= max(freq % 2 == 0 ? freq - 2 : freq - 1, 0);
        }
        return n;
    }
};