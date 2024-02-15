class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        vector<pair<int, int>> v;
        unordered_map<int, int> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            mp[arr[i]]++;
        for (auto it : mp)
            v.push_back({it.first, it.second});
        sort(v.begin(), v.end(), [](pair<int,int>a,pair<int,int>b){return a.second > b.second;});
        int count = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (k != 0 && k - v[i].second >= 0)
            {
                k = k - v[i].second;
                count++;
            }
            else
                break;
        }
        return v.size() - count;
    }
};