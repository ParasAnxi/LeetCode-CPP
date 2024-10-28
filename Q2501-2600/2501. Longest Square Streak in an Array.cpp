class Solution
{
public:
    int longestSquareStreak(std::vector<int> &nums)
    {
        unordered_set<int> mp(nums.begin(), nums.end()); 
        int ans = -1;

        for (int i : nums)
        {
            int count = 1;
            long long curr = i;

            while (mp.count(curr * curr))
            {
                count++;
                curr *= curr;
            }

            if (count > 1)
            {
                ans = max(ans, count);
            }
        }

        return ans;
    }
};