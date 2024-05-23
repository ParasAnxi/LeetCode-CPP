class Solution
{
public:
private:
    int solve(vector<int> &nums, int k, unordered_map<int, int> &freq, int i)
    {
        if (i == nums.size())
        {
            return 1;
        }
        int ans = solve(nums, k, freq, i + 1);
        if (!freq[nums[i] - k] && !freq[nums[i] + k])
        {
            freq[nums[i]]++;
            ans += solve(nums, k, freq, i + 1);
            freq[nums[i]]--;
        }
        return ans;
    }

public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        return solve(nums, k, freq, 0) - 1;
    }
};