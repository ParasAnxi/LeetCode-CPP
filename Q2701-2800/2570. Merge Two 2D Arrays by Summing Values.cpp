class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        vector<vector<int>> ans;
        map<int, int> mp;

        for (auto &i : nums1)
        {
            if (!mp[i[0]])
                mp[i[0]] = i[1];
            else
                mp[i[0]] += i[1];
        }
        for (auto &i : nums2)
        {
            if (!mp[i[0]])
                mp[i[0]] = i[1];
            else
                mp[i[0]] += i[1];
        }

        for (auto &i : mp)
        {
            ans.push_back({i.first, i.second});
        }
        return ans;
    }
};