class Solution
{
public:
    int solve(int index, int maxi, vector<int> &arr, vector<int> &dp)
    {
        if (index < 0)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int ans = 0;
        for (int i = 1; i <= maxi; i++){
            if (index - i < -1)
                continue;
            int temp = 0;
            for (int j = index; j > index - i; j--)
                temp = max(temp, arr[j]);
            ans = max(ans, solve(index - i, maxi, arr, dp) + temp * i);
        }
        return dp[index] = ans;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k){
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(n - 1, k, arr, dp);
    }
};