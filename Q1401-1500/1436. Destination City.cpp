class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        map<string, pair<int, int>> mp;
        for (auto &i : paths)
        {
            string src = i[0], dest = i[1];
            mp[src].second++;
            mp[dest].first++;
        }

        for (auto &i : mp)
        {
            if (i.second.second == 0)
            {
                return i.first;
            }
        }

        return "";
    }
};