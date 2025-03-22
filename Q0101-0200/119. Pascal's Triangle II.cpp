class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row;
        long long ans = 1;
        int n = rowIndex + 1;
        row.push_back(ans);
        for (int i = 1; i < n; i++)
        {
            ans = ans * (n - i);
            ans = ans / i;
            row.push_back(ans);
        }
        return row;
    }
};