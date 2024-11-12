class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        sort(items.begin(), items.end());
        int n = items.size();
        int m = queries.size();
        vector<int> v;
        vector<int> prices;
        for (auto item : items)
        {
            if (v.empty() || v.back() < item[1])
            {
                v.push_back(item[1]);
                prices.push_back(item[0]);
            }
        }
        vector<int> ans;
        for (auto q : queries)
        {
            int idx = 0;
            while (idx < prices.size() && prices[idx] <= q)
            {
                idx++;
            }
            if (idx == 0)
                ans.push_back(0);
            else
                ans.push_back(v[idx - 1]);
        }
        return ans;
    }
};