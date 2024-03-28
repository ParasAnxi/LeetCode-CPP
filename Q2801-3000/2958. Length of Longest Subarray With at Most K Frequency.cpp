class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int len = 0, maxi = 0;
        int i = 0, j = 0;
        while (j < nums.size())
        {
            if (freq[nums[j]] < k)
            {
                freq[nums[j]]++;
                j++;
            }
            else
            {
                while (freq[nums[j]] >= k)
                {
                    freq[nums[i]]--;
                    i++;
                }
            }
            len = j - i;
            maxi = max(maxi, len);
        }
        return maxi;
    }
};