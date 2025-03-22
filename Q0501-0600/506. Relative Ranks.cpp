class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<int> v = score;
        vector<string> t(n);
        sort(v.rbegin(), v.rend());
        map<int, string> mp;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                mp[v[i]] = "Gold Medal";
            }
            else if (i == 1)
            {
                mp[v[i]] = "Silver Medal";
            }
            else if (i == 2)
            {
                mp[v[i]] = "Bronze Medal";
            }
            else
            {
                mp[v[i]] = to_string(i + 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            t[i] = mp[score[i]];
        }
        return t;
    }
};