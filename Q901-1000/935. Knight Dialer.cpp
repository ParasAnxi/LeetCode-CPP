class Solution
{
public:
    int knightDialer(int n)
    {
        vector<vector<int>> adj = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
        long res = 0, mod = 1e9 + 7;
        vector<int> v(10);
        for (int i = 0; i < 10; i++)
            v[i] = 1;
        for (int i = 1; i < n; i++)
        {
            vector<int> u(10, 0);
            for (int k = 0; k < 10; k++)
            {
                for (int j : adj[k])
                    u[j] = (u[j] + v[k]) % mod;
            }
            v = u;
        }
        for (long i : v)
        {
            res = (res + i) % mod;
        }
        return res;
    }
};