class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &arr, int m, int n)
    {
        vector<vector<int>> ans(m, vector<int>(n, 0));
        if (m * n != arr.size())
        {
            return {};
        }
        for (int i = 0; i < arr.size(); i++)
        {
            int x = i;
            int row = x / n;
            int col = x % n;
            ans[row][col] = arr[i];
        }
        return ans;
    }
};