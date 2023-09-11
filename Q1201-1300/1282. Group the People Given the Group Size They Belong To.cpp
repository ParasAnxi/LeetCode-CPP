class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < groupSizes.size(); i++)
        {
            int a = groupSizes[i];
            m[a].push_back(i);
            if (a == m[a].size())
            {
                ans.push_back(m[a]);
                m[a].clear();
            }
        }
        return ans;
    }
};