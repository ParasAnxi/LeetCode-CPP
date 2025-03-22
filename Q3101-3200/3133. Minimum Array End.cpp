class Solution
{
public:
    long long minEnd(int n, int x)
    {
        long long ans = x, left = 1, right = n - 1;
        while (right)
        {
            if (!(ans & left))
            {
                if (right & 1)
                    ans |= left;
                right = right >> 1;
            }
            left = left << 1;
        }
        return ans;
    }
};