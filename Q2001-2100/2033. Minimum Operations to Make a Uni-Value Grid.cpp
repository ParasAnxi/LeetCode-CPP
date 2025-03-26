class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int m = grid.size();
        int n = grid[0].size();
        int r = grid[0][0] % x;
        vector<int> v(m * n, 0);
        int count = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] % x != r){
                    return -1;
                    break;
                }
                v[count] = grid[i][j];
                count++;
            }
        }
        sort(v.begin(), v.end());
        int ans = INT_MAX;
        if (m * n % 2 == 0){
            int op = 0;
            for (int i = 0; i < m * n; i++){
                op += abs(v[i] - v[m * n / 2]) / x;
            }
            ans = min(ans, op);
            op = 0;
            for (int i = 0; i < m * n; i++)
            {
                op += abs(v[i] - v[(m * n - 2) / 2]) / x;
            }
            ans = min(ans, op);
        }
        else{
            int op = 0;
            for (int i = 0; i < m * n; i++)
            {
                op += abs(v[i] - v[(m * n - 1) / 2]) / x;
            }
            ans = min(ans, op);
        }
        return ans;
    }
};