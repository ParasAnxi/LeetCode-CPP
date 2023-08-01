class Solution
{
public:
    void backtrack(int n, int k, int i, vector<int> &curr, vector<vector<int>> &ans)
    {
        if (curr.size() == k)
        {
            ans.push_back(curr);
        }
        else
        {
            for (int j = i; j <= n; j++)
            {
                curr.push_back(j);
                backtrack(n, k, j + 1, curr, ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(n, k, 1, curr, ans);
        return ans;
    }
};