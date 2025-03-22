class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> v(n + 1, 0);
        int s = 0;
        int e = 0;
        for (int i = 0; i < n; ++i)
        {
            while (s + v[i] < nums[i])
            {
                if (e == queries.size())
                    return -1;

                int st = queries[e][0];
                int md = queries[e][1];
                int en = queries[e][2];
                e++;

                if (md < i)
                    continue;

                v[max(st, i)] += en;
                v[md + 1] -= en;
            }
            s += v[i];
        }
        return e;
    }
};