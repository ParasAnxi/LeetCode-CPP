class Solution
{
public:
    int find(int x, vector<int> &p)
    {
        if (p[x] != x)
            p[x] = find(p[x], p);
        return p[x];
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);

        for (auto &e : edges)
        {
            p[find(e[0], p)] = find(e[1], p);
        }
        return find(source, p) == find(destination, p);
    }
};