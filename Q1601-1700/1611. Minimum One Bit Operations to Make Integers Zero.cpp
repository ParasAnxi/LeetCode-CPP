class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        int i;
        int x = __builtin_parity(n);
        int ans = 0;

        for (i = 0; 1 << i <= n; i++)
        {
            ans |= x << i;
            x ^= n >> i & 1;
        }
        return ans;
    }
};