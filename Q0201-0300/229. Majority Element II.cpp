class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        map<int, int> m;
        vector<int> ans;
        int n = floor(nums.size() / 3);
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (auto x : m)
        {
            if (x.second > n)
                ans.push_back(x.first);
        }
        return ans;
    }
};