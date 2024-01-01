class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        vector<vector<int>> ans;
        for (int i : nums)
        {
            vector<int> temp;
            temp.push_back(i);
            if (mp.find(i) != mp.end())
            {
                if (ans.size() <= mp[i])
                    ans.push_back(temp);
                else
                    ans[mp[i]].push_back(i);
            }
            else
            {
                if (ans.empty())
                    ans.push_back(temp);
                else
                    ans[0].push_back(i);
            }
            mp[i]++;
        }

        return ans;
    }
};