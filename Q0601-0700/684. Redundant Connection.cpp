class Solution
{
    

public:
    int find(int v, vector<int>& parent)
    {
        if (parent[v] != v)
        {
            parent[v] = find(parent[v],parent);
        }
        return parent[v];
    }
    void join(int u, int v, vector<int>& parent)
    {
        u = find(u,parent);
        v = find(v,parent);
        if (u != v)
        {
            parent[u] = v;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> parent;
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        for (auto &i : edges)
        {
            int u = i[0], v = i[1];
            int parentU = find(u,parent);
            int parentV = find(v,parent);
            if (parentU == parentV)
                return i;
            join(parentU, parentV,parent);
        }
        return {};
    }
};