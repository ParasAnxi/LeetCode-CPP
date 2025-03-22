class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        int start = 0, maxLen = 1;
        for (int i = 0; i < n; i++)
        {
            int r = i;

            while (r < n && s[i] == s[r])
                r++;

            int l = i - 1;

            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
            }

            l++, r--;
            int len = r - l + 1;
            if (len > maxLen)
            {
                maxLen = len;
                start = l;
            }
        }
        return s.substr(start, maxLen);
    }
};