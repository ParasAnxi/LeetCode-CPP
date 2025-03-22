class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int ans = 0;
        vector<map<int, int>> v(nums.size());
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                long diff = (long)nums[i] - (long)nums[j];
                if (diff >= INT_MAX || diff <= INT_MIN)
                    continue;
                int d = int(diff);
                ans += v[j][d];
                v[i][d] += v[j][d] + 1;
            }
        }
        return ans;
    }
};