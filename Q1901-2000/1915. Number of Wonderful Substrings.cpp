class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        long long ans = 0;
        int mask = 0;
        vector<int> maskCount(1024, 0);
        maskCount[0] = 1;

        for (char c : word)
        {
            mask ^= 1 << (c - 'a');
            ans += maskCount[mask];
            for (int i = 0; i < 10; ++i)
            {
                int res = mask ^ (1 << i);
                ans += maskCount[res];
            }
            maskCount[mask]++;
        }

        return ans;
    }
};