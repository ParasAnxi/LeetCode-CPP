class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> p;
        for (int i = 0; i < mat.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < mat[0].size(); j++)
            {
                sum += mat[i][j];
            }
            p.push_back({sum, i});
        }
        sort(p.begin(), p.end());
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(p[i].second);
        }
        return ans;
    }
};