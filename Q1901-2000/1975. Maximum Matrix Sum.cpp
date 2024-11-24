class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int count = 0;
        int mini = INT_MAX;
        long ans = 0;
        bool zero = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = abs(matrix[i][j]);
                ans += temp;
                mini = min(temp, mini);
                if (matrix[i][j] < 0)
                    count++;
                else if (matrix[i][j] == 0)
                    zero = true;
            }
        }
        if (zero)
            return ans;
        if (count & 1)
            return ans - (2 * mini);
        return ans;
    }
};