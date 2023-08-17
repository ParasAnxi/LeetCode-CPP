class Solution
{
public:
    bool isPalindrome(int x)
    {
        long int y = x, s = 0, temp;
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        else
        {
            while (y != 0)
            {
                temp = y % 10;
                s = 10 * s + temp;
                y = y / 10;
            }
            return x == s || x == s / 10;
        }
    }
};