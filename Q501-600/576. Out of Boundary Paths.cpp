class Solution
{
public:
    bool isSafe(int i, int j, int n, int m){
        if (i < 0 || j < 0 || j >= m || i >= n)
            return false;
        return true;
    }
    long long solve(int i, int j, int n, int m, int k, vector<vector<vector<long long>>> &dp){
        if (k == 0){
            if (isSafe(i, j, n, m))
                return 0;
            return 1;
        }
        if (!isSafe(i, j, n, m))
            return 1;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        long long l = solve(i, j - 1, n, m, k - 1, dp);
        long long r = solve(i, j + 1, n, m, k - 1, dp);
        long long u = solve(i - 1, j, n, m, k - 1, dp);
        long long d = solve(i + 1, j, n, m, k - 1, dp);
        long long t = (l + r + u + d) % (long long)(1e9 + 7);
        return dp[i][j][k] = t;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(maxMove + 1, -1)));
        long long ans = solve(startRow, startColumn, m, n, maxMove, dp) % (long long)(1e9 + 7);
        return ans;
    }
};