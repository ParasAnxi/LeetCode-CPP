class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> adj(n, 0);
        for (int i = 0; i < roads.size(); i++)
        {
            int start = roads[i][0];
            int end = roads[i][1];
            adj[start]++;
            adj[end]++;
        }
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i)
        {
            v.push_back({adj[i], i});
        }
        sort(v.rbegin(), v.rend());
        int j = 0;
        vector<int> val(n, 0);
        for (auto &pair : v)
        {
            val[pair.second] = n - j;
            j++;
        }
        long long maxi = 0;
        for (int i = 0; i < roads.size(); i++)
        {
            maxi += val[roads[i][0]] + val[roads[i][1]];
        }
        return maxi;
    }
};