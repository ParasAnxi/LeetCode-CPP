class Solution
{
public:
    int countVowelPermutation(int n)
    {
        int mod = 1000000007;
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        while (--n)
        {
            long long a2, e2, i2, o2, u2;
            a2 = e;
            e2 = (a + i) % mod;
            i2 = ((a + e) % mod + (o + u) % mod) % mod;
            o2 = (i + u) % mod;
            u2 = a;
            a = a2, e = e2, i = i2, o = o2, u = u2;
        }
        int ans = (a + e) % mod;
        ans = (ans + i) % mod;
        ans = (ans + o) % mod;
        ans = (ans + u) % mod;
        return ans;
    }
};