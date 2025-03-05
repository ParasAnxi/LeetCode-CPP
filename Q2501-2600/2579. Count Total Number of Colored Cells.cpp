class Solution
{
public:
    long long coloredCells(int n)
    {
        long long ans = n;
        return (2 * (ans - 1) * ans + 1);
    }
};