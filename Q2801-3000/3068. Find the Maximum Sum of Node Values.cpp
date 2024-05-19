class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long ans = 0;
        int count = 0;
        int pMini = INT_MAX;
        int nMaxi = INT_MIN;

        for (int val : nums)
        {
            int op = val ^ k;
            ans += val;
            int res = op - val;

            if (res > 0)
            {
                pMini = min(pMini, res);
                ans += res;
                count += 1;
            }
            else
            {
                nMaxi = max(nMaxi, res);
            }
        }

        if (count % 2 == 0)
        {
            return ans;
        }
        return max(ans - pMini, ans + nMaxi);
    }
};