class Solution
{
public:
    bool isPossible(vector<vector<int>> &grid, int i, int j, int sum)
    {
        int s = 0, t = 0;

        for (int k = i, l = j, p = j + 2; k <= i + 2 && l <= j + 2 && p >= j; k++, l++, p--)
        {
            s += grid[k][l];
            t += grid[k][p];
        }
        if (s == t && s == sum)
            return 1;
        return 0;
    }
    bool solve(vector<vector<int>> &grid, int i, int j)
    {
        vector<bool> v(10, 0);
        int r = 0, c = 0, target = -1;
        for (int k = i; k <= i + 2; k++)
        {
            r = 0;
            for (int l = j; l <= j + 2; l++)
            {
                if (grid[k][l] > 9 || grid[k][l] == 0)
                    return 0;
                if (v[grid[k][l]] == 1)
                    return 0;
                else
                    v[grid[k][l]] = 1;
                r += grid[k][l];
            }
            if (target == -1)
                target = r;
            else if (target == r)
                continue;
            else
                return 0;
        }

        for (int l = j; l <= j + 2; l++)
        {
            c = 0;
            for (int k = i; k <= i + 2; k++)
            {
                c += grid[k][l];
            }
            if (target == c)
                continue;
            else
                return 0;
        }
        if (isPossible(grid, i, j, target) == 1)
            return 1;
        return 0;
    }
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if (n < 3 || m < 3)
            return 0;
        int count = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < m - 2; j++)
            {
                count += solve(grid, i, j);
            }
        }
        return count;
    }
};