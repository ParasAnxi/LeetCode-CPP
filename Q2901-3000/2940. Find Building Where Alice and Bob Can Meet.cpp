class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &q)
    {
        vector<pair<int, int>> v;
        int n = heights.size();
        vector<vector<pair<int, int>>> vp(n);
        for (int i = 0; i < q.size(); i++)
        {
            if (q[i][0] > q[i][1])
                swap(q[i][0], q[i][1]);
            vp[q[i][1]].push_back({q[i][0], i});
        }
        vector<int> ans(q.size());
        for (int i = n - 1; i >= 0; i--)
        {
            while (!v.empty() && v.back().first <= heights[i])
                v.pop_back();
            for (int j = 0; j < vp[i].size(); j++)
            {
                if (heights[vp[i][j].first] < heights[i])
                {
                    ans[vp[i][j].second] = i;
                    continue;
                }
                if (vp[i][j].first == i)
                {
                    ans[vp[i][j].second] = i;
                    continue;
                }
                pair<int, int> p = {max(heights[i], heights[vp[i][j].first]), 1e9};
                int x = upper_bound(v.rbegin(), v.rend(), p) - v.rbegin();
                if (x == v.size())
                    ans[vp[i][j].second] = -1;
                else
                    ans[vp[i][j].second] = v[v.size() - x - 1].second;
            }
            v.push_back({heights[i], i});
        }
        return ans;
    }
};