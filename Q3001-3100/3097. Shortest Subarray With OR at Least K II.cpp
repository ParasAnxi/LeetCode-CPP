class Solution
{
public:
    int minimumSubarrayLength(vector<int> &v, int k)
    {
        int ans = INT_MAX;
        int count[30] = {};
        int val = 0;
        for (int i = 0, j = 0; i < v.size(); ++i)
        {
            int x = v[i];
            for (int l = 0; x; x >>= 1, ++l)
            {
                if (x & 1)
                {
                    count[l]++;
                    val |= (1 << l);
                }
            }
            while (val >= k && j <= i)
            {
                ans = min(ans, i - j + 1);
                int x = v[j];
                j++;
                for (int i = 0; x; x >>= 1, ++i)
                {
                    if (x & 1)
                    {
                        count[i]--;
                        (count[i] == 0) && (val &= ~(1 << i));
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};