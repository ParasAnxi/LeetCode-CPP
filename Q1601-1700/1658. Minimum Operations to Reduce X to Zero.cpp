class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = 0;
        for (auto x : nums)
            sum += x;
        sum -= x;
        if (sum < 0)
            return -1;
        int i = 0, j = 0, ans = INT_MAX, curr = 0;
        while (j < nums.size())
        {
            curr += nums[j++];
            if (curr == sum)
            {
                int len = nums.size() - (j - i);
                ans = min(ans, len);
            }
            while (curr > sum)
            {
                curr -= nums[i++];
            }
            if (curr == sum)
            {
                int len = nums.size() - (j - i);
                ans = min(ans, len);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};