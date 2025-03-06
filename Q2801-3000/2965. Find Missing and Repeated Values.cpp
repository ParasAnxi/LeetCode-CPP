class Solution
{
public:
    vector<int> findmissAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int n2 = n * n;
        vector<int> freq(n2 + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                freq[grid[i][j]]++;
            }
        }
        int rep, miss;
        for (int i = 1; i < n2 + 1; i++)
        {
            if (freq[i] == 2)
                rep = i;
            if (freq[i] == 0)
                miss = i;
        }
        return {rep, miss};
    }
};