class Solution
{
public:
    int findComplement(int num)
    {
        if (num == 0)
            return 1;
        int ans = 0;
        int x = 0;
        while (num > 0)
        {
            int bits = num & 1;
            int rev = 1 - bits;
            ans = ans + rev * (pow(2, x));
            x++;
            num = num / 2;
        }
        return ans;
    }
};