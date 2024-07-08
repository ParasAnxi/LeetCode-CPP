class Solution
{
public:
    void solve(int &ans, vector<int> &v, int i, int k)
    {
        if (v.size() == 1)
        {
            ans = v[0];
            return;
        }
        i = (i + (k - 1)) % v.size();
        v.erase(v.begin() + i);
        solve(ans, v, i, k);
    }

    int findTheWinner(int n, int k)
    {
        int ans = -1;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back(i + 1);
        }
        int i = 0;
        solve(ans, v, i, k);
        return ans;
    }
};