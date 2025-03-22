class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int n = version1.size(), m = version2.size();
        int left = 0, right = 0;
        int a = 0, b = 0;
        while (left < n || right < m)
        {
            while (left < n && version1[left] != '.')
            {
                a = a * 10 + (version1[left++] - '0');
            }
            while (right < m && version2[right] != '.')
            {
                b = b * 10 + (version2[right++] - '0');
            }
            if (a < b)
                return -1;
            else if (a > b)
                return 1;
            left++;
            right++;
            a = 0;
            b = 0;
        }
        return 0;
    }
};