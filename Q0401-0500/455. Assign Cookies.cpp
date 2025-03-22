class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int ans = 0, i = 0, j = 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j])
            {
                ans++;
                i++;
                j++;
            }
            else if (g[i] > s[i])
            {
                j++;
            }
        }
        return ans;
    }
};