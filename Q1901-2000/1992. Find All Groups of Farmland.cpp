class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> ans;
        int r = 0;
        int c = 0;

        for (int i = 0; i < land.size(); i++)
        {
            for (int j = 0; j < land[0].size(); j++)
            {
                if (land[i][j] && (i == 0 || !land[i - 1][j]) && (j == 0 || !land[i][j - 1]))
                {
                    r = i;
                    c = j;
                    while (++r < land.size() && land[r][j])
                    {
                    }
                    while (++c < land[0].size() && land[i][c])
                    {
                    }
                    ans.push_back({i, j, r - 1, c - 1});
                }
            }
        }
        return ans;
    }
};