class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for (int i = 0; i < walls.size(); i++)
        {
            matrix[walls[i][0]][walls[i][1]] = 2;
        }
        for (int i = 0; i < guards.size(); ++i)
        {
            matrix[guards[i][0]][guards[i][1]] = 3;
        }
        for (int i = 0; i < guards.size(); i++)
        {
            int row = guards[i][0], col = guards[i][1];
            for (int i = row + 1; i < m; i++)
            {
                if (matrix[i][col] == 2 or matrix[i][col] == 3)
                {
                    break;
                }
                matrix[i][col] = 1;
            }
            for (int i = row - 1; i >= 0; i--)
            {
                if (matrix[i][col] == 2 or matrix[i][col] == 3)
                {
                    break;
                }
                matrix[i][col] = 1;
            }
            for (int j = col + 1; j < n; j++)
            {
                if (matrix[row][j] == 2 or matrix[row][j] == 3)
                {
                    break;
                }
                matrix[row][j] = 1;
            }
            for (int j = col - 1; j >= 0; j--)
            {
                if (matrix[row][j] == 2 or matrix[row][j] == 3)
                {
                    break;
                }
                matrix[row][j] = 1;
            }
        }
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                    ans++;
            }
        }
        return ans;
    }
};