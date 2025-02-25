class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int n = arr.size(), MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) arr[i] %= 2;

        int ans = 0, curr = 0;
        int count[2] = {0, 0};
        for (int i = 0; i < n; i++)
        {
            curr += arr[i];
            count[curr % 2]++;
            ans += (count[1 - curr % 2]) % MOD;
            if (curr % 2)
                ans++;
            count[curr % 2] %= MOD;
            ans %= MOD;
        }
        return ans;
    }
};