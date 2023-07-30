class Solution
{
public:
    int strangePrinter(string s)
    {
        string str = "";
        for (auto &c : s)
            if (str.empty() || str.back() != c)
                str += c;
        vector<vector<int>> v(str.size(), vector<int>(str.size(), -1));
        return dfs(str, 0, str.size() - 1, v);
    }
    int dfs(string &p, int l, int r, vector<vector<int>> &v)
    {
        if (l >= r)
            return l == r;
        if (v[l][r] != -1)
            return v[l][r];
        v[l][r] = dfs(p, l + 1, r, v) + 1;
        for (int k = l + 1; k <= r; k++)
            if (p[k] == p[l])
                v[l][r] = min(v[l][r], dfs(p, l, k - 1, v) + dfs(p, k + 1, r, v));
        return v[l][r];
    }
};