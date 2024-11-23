class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++)
        {
            int ptr = n - 1;
            for (int j = n - 1; j >= 0; j--)
            {
                if (box[i][j] == '*')
                {
                    ans[j][m - 1 - i] = '*';
                    if (j != 0)
                        ptr = j - 1;
                }
                else if (box[i][j] == '#')
                {
                    ans[ptr][m - 1 - i] = '#';
                    if (ptr != 0)
                        ptr--;
                }
            }
        }
        return ans;
    }
};