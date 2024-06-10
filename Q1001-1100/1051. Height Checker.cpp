class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> v = heights;
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] != v[i])
                ans++;
        }
        return ans;
    }
};