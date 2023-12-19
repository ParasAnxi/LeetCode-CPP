class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int ans, cnt = 1;
                ans = img[i][j];
                if (i - 1 >= 0 and j - 1 >= 0)
                {
                    ans += img[i - 1][j - 1];
                    cnt++;
                }
                if (i - 1 >= 0 and j + 1 < m)
                {
                    ans += img[i - 1][j + 1];
                    cnt++;
                }
                if (i - 1 >= 0)
                {
                    ans += img[i - 1][j];
                    cnt++;
                }
                if (i + 1 < n and j - 1 >= 0)
                {
                    ans += img[i + 1][j - 1];
                    cnt++;
                }
                if (i + 1 < n and j + 1 < m)
                {
                    ans += img[i + 1][j + 1];
                    cnt++;
                }
                if (i + 1 < n)
                {
                    ans += img[i + 1][j];
                    cnt++;
                }
                if (j + 1 < m)
                {
                    ans += img[i][j + 1];
                    cnt++;
                }
                if (j - 1 >= 0)
                {
                    ans += img[i][j - 1];
                    cnt++;
                }

                res[i].push_back(ans / cnt);
            }
        }

        return res;
    }
};