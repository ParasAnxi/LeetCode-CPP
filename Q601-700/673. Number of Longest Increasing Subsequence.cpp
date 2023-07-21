class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> length(n, 1);
        vector<int> count(n, 1);
        int maxLength = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (1 + length[j] > length[i])
                    {
                        length[i] = 1 + length[j];
                        count[i] = count[j];
                    }
                    else if (1 + length[j] == length[i])
                    {
                        count[i] += count[j];
                    }
                }
            }
            maxLength = max(maxLength, length[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (length[i] == maxLength)
            {
                ans += count[i];
            }
        }
        return ans;
    }
};