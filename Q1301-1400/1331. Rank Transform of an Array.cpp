class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = {arr[i], i};
        sort(v.begin(), v.end());
        int curr = 0, prev = INT_MIN;
        vector<int> ans(n);
        for (auto &p : v)
        {
            if (p.first > prev)
            {
                curr++;
                prev = p.first;
            }
            ans[p.second] = curr;
        }
        return ans;
    }
};