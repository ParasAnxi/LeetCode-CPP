class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> a(matrix.size());
        vector<int> b(matrix[0].size());
        for (int i = 0; i < matrix.size(); i++){
            int mini = matrix[i][0];

            for (int j = 0; j < matrix[0].size(); j++){
                mini = min(mini, matrix[i][j]);
                b[j] = max(b[j], matrix[i][j]);
            }
            a[i] = mini;
        }

        vector<int> ans;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                if (a[i] == b[j])
                {
                    ans.push_back(a[i]);
                }
            }
        }

        return ans;
    }
};