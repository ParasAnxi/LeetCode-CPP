class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> ans;
        unordered_map<int, int> mp;
        vector<int> temp;
        for (auto it : target)
            mp[it]++;
        for (int i = 1; i <= n; i++)
        {
            if (temp == target)
                break;
            if (mp.find(i) == mp.end())
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            else
            {
                temp.push_back(i);
                ans.push_back("Push");
            }
        }
        return ans;
    }
};