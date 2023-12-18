class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int a1 = 0, a2 = 0, b1 = 10001, b2 = 10001;
        for (int a : nums)
        {
            if (a > a2)
                a2 = a;
            if (a > a1)
            {
                a2 = a1;
                a1 = a;
            }
            if (a < b2)
                b2 = a;
            if (a < b1)
            {
                b2 = b1;
                b1 = a;
            }
        }
        return a1 * a2 - b1 * b2;
    }
};