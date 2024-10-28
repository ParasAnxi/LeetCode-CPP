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

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        int n = nums.size();
        set<long long> s;
        for (auto i : nums)
        {
            s.insert(i);
        }
        int ans = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            int count = 1;
            long long mul = pow(nums[i], 2);
            while (s.count(mul))
            {
                count++;
                mul = pow(mul, 2);
            }
            if (count > 1)
                ans = max(ans, count);
        }
        return ans;
    }
};