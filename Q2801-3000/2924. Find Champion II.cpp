class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        map<int, int> m;
        for (const vector<int> &edge : edges)
        {
            m[edge[1]]++;
        }

        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            if (m[i] == 0 && ans != -1)
                return -1;

            if (m[i] == 0)
                ans = i;
        }
        return ans;
    }
};