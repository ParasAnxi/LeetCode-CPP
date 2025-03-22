class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int a = 0;
        int b = sqrt(c);
        while (a <= b)
        {
            long long sum = pow(a, 2) + pow(b, 2);
            if (sum == c)
                return true;
            else if (sum < c)
                a++;
            else
                b--;
        }
        return false;
    }
};