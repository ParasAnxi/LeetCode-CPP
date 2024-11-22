class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        map<vector<int>, int> mp;

        for (int i = 0; i < n; i++)
        {
            int curr = matrix[i][0];
            vector<int> zero, one;
            bool flag = true;

            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] != curr)
                {
                    flag = false;
                }
                if (matrix[i][j] == 0)
                    zero.push_back(j);
                else
                    one.push_back(j);
            }
            if (!flag)
            {
                mp[one]++;
                mp[zero]++;
            }
            else
            {
                count++;
            }
        }
        int res = 0;
        for (auto it : mp)
        {
            res = max(res, it.second);
        }
        return max(count, res);
    }
};