class Solution
{
public:
    void solve(int k, vector<vector<int>> &condition, unordered_map<int, int> &position)
    {
        vector<vector<int>> v(k + 1);
        vector<int> parents(k + 1, 0);
        for (auto i : condition)
        {
            v[i[0]].push_back(i[1]);
            parents[i[1]]++;
        }
        int index = 0;
        queue<int> q;
        for (int i = 1; i <= k; i++)
        {
            if (parents[i] == 0)
            {
                q.push(i);
                position[i] = index++;
            }
        }
        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            for (auto child : v[parent])
            {
                if (--parents[child] == 0)
                {
                    q.push(child);
                    position[child] = index++;
                }
            }
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        vector<vector<int>> ans(k, vector<int>(k, 0));
        unordered_map<int, int> row;
        unordered_map<int, int> col;
        solve(k, rowConditions, row);
        solve(k, colConditions, col);
        if (row.size() != k || col.size() != k)
        {
            return {};
        }
        for (int i = 1; i <= k; i++)
        {
            ans[row[i]][col[i]] = i;
        }
        return ans;
    }
    
};