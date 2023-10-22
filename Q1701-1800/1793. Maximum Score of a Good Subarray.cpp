class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int s = k;
        int e = k;
        int mini = nums[k];
        int maxAns = mini;

        while (s > 0 || e < nums.size() - 1)
        {
            if (s == 0)
                e++;
            else if (e == nums.size() - 1)
                s--;
            else if (nums[s - 1] > nums[e + 1])
                s--;
            else
                e++;
            mini = min(mini, min(nums[s], nums[e]));
            maxAns = max(maxAns, mini * (e - s + 1));
        }
        return maxAns;
    }
};