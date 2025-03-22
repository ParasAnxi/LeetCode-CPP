class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        vector<int> bitset(32, 0);
        int n = nums.size();

        for (auto a : nums)
        {
            for (int i = 0; i < 32; i++)
            {
                bitset[i] += ((a >> i) & 1);
            }
        }

        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            int bit = ((k >> i) & 1);
            if (bit && bitset[i] % 2 == 0)
            {
                res++;
            }
            else if (!bit && bitset[i] % 2)
            {
                res++;
            }
        }

        return res;
    }
};