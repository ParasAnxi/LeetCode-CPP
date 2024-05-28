class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        vector<int> v(s.size(), 0);
        for (int i = 0; i < s.size(); i++)
        {
            v[i] = abs(s[i] - t[i]);
        }
        int l = 0, r = 0;
        int curr = 0;
        int ans = 0;
        while (r < v.size())
        {
            curr += v[r];
            while (curr > maxCost && l <= r && l + 1 < v.size())
            {
                curr -= v[l];
                l++;
            }

            if (curr <= maxCost)
                ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};