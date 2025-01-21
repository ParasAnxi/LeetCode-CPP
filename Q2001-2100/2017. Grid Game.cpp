class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        long long int x = 0;
        long long int y = 0;
        long long int mini = LLONG_MAX;

        int cols = grid[0].size();
        for (int i = 0; i < cols; i++)
            x += grid[0][i];
        for (int i = 0; i < cols; i++)
        {
            x -= grid[0][i];
            mini = min(mini, max(x, y));
            y += grid[1][i];
        }

        return mini;
    }
};