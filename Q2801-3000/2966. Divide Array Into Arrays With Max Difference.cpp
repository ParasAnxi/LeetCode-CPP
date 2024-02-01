class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 1;
        while (i < n)
        {
            if (curr.size() == 0 && nums[i] - nums[i - 1] <= k)
            {
                curr.push_back(nums[i - 1]);
                curr.push_back(nums[i]);
            }
            else if (curr.size() == 2 && nums[i] - curr[0] <= k)
            {
                curr.push_back(nums[i]);
                ans.push_back(curr);
                curr.clear();
                i++;
            }
            i++;
        }
        if (ans.empty() || ans.size() * ans[0].size() != n)
        {
            ans.clear();
        }
        return ans;
    }
};