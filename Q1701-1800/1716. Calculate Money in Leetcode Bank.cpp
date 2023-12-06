class Solution
{
public:
    int totalMoney(int n)
    {
        int weeks = n / 7;
        int ans = 0;
        int days = n - 7 * weeks;
        int week = 0;
        int start = 0;

        while (weeks--)
        {
            start = week + 1;
            int i = 7;
            while (i--)
            {
                ans = ans + start;
                start++;
            }
            week++;
        }
        week++;
        while (days--)
        {
            ans = ans + week;
            week++;
        }
        return ans;
    }
};