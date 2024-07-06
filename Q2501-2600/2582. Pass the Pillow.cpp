class Solution
{
public:
    int passThePillow(int n, int time)
    {
        if (n - 1 >= time)
        {
            return time + 1;
        }
        else
        {
            int div = time / (n - 1);
            if (div % 2 == 0)
            {
                return 1 + time % (n - 1);
            }
            else
            {
                return n - time % (n - 1);
            }
        }
        return -1;
    }
};