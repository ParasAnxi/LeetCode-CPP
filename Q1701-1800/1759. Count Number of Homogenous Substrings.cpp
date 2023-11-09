class Solution
{
public:
    int sum(int n, int m)
    {
        if (n % 2 == 0)
        {
            return 1ll * (n / 2) * 1ll * (n + 1) % m;
        }
        else
        {
            return 1ll * n * 1ll * ((n + 1) / 2) % m;
        }
    }
    int countHomogenous(string s)
    {
        s = s + 'Z';
        int n = s.length();
        int count = 0;
        int currCount = 1;
        int mod = 1e9 + 7;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                int currVal = sum(currCount, mod);
                count = (count + currVal) % mod;
                currCount = 0;
            }
            currCount++;
        }
        return count;
    }
};