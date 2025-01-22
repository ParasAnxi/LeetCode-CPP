class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> v(n, vector<int>(m, -1));
        int index = n + m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isWater[i][j] == 1)
                {
                    v[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 0)
                    continue;
                int top = index, left = index;
                if (i - 1 >= 0)
                    top = v[i - 1][j];
                if (j - 1 >= 0)
                    left = v[i][j - 1];
                v[i][j] = min(top, left) + 1;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (v[i][j] == 0)
                    continue;
                int bottom = index, right = index;
                if (i + 1 < n)
                    bottom = v[i + 1][j];
                if (j + 1 < m)
                    right = v[i][j + 1];
                v[i][j] = min(v[i][j], min(bottom, right) + 1);
            }
        }
        return v;
    }
};