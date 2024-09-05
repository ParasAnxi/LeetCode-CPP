class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int totalSum = mean * (n + m);
        int mSum = accumulate(rolls.begin(), rolls.end(), 0);

        int nSum = totalSum - mSum;

        if (nSum < n || nSum > n * 6)
        {
            return {};
        }

        vector<int> ans(n, 1);

        int rem = nSum - n;

        for (int i = 0; rem > 0 && i < n; ++i)
        {
            int add = min(rem, 5);
            ans[i] += add;
            rem -= add;
        }

        return ans;
    }
};