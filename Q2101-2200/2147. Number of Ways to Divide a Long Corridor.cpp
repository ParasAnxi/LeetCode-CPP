class Solution
{
public:
    int dp[100001][3];
    int mod = 1000000007;
    int solve(string &corridor, int cnt, int index)
    {
        if (cnt > 2)
        {
            return 0;
        }
        if (index >= corridor.size())
        {
            if (cnt == 2)
            {
                return 1;
            }
            return 0;
        }
        if (dp[index][cnt] != 0)
        {
            return dp[index][cnt] - 1;
        }

        int ans = 0;
        if (corridor[index] == 'P')
        {
            if (cnt == 2)
            {
                ans += solve(corridor, 0, index + 1);
                ans = ans % mod;
            }
            ans += solve(corridor, cnt, index + 1);
            ans = ans % mod;
        }
        else
        {
            if (cnt == 2)
            {
                ans += solve(corridor, 1, index + 1);
                ans = ans % mod;
            }
            else
            {
                ans += solve(corridor, cnt + 1, index + 1);
                ans = ans % mod;
            }
        }
        dp[index][cnt] = ans + 1;
        return ans;
    }
    int numberOfWays(string corridor)
    {
        return solve(corridor, 0, 0);
    }
};