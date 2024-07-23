class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_mp<int, int> mp;
        for (auto i : nums)
        {
            mp[i] = mp[i] + 1;
        }
        vector<pair<int, int>> v;
        for (auto i : mp)
        {
            pair<int, int> temp = {i.first, i.second};
            v.push_back(temp);
        }
        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
            if(a.second==b.second){
                return a.first>b.first;
            }
            else{
                return a.second<b.second;
            } });
        vector<int> ans;
        for (auto i : v)
        {
            int temp = i.first;
            for (int j = 0; j < i.second; j++)
            {
                ans.push_back(temp);
            }
        }
        return ans;
    }
};