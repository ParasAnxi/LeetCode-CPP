class Solution
{
public:
    int solve(vector<int> arr, int start, int end)
    {
        int ans = 0;
        for (int i = start; i <= end; i++)
        {
            ans = ans ^ arr[i];
        }
        return ans;
    }
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];
            int res = solve(arr, left, right);
            ans.push_back(res);
        }
        return ans;
    }
};