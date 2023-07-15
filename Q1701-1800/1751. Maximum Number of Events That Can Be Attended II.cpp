class Solution{
public:
    vector<vector<int>> dp;
    int maxValue(vector<vector<int>> &events, int k){
        sort(events.begin(), events.end());
        int n = events.size();
        dp.resize(n, vector<int>(k + 1, -1));
        return solve(events, 0, k, 0);
    }
    int solve(vector<vector<int>> &events, int idx, int k, int end){
        if (idx == events.size())
            return 0;
        if (k == 0)
            return 0;
        if (events[idx][0] <= end)
            return solve(events, idx + 1, k, end);
        if (dp[idx][k] != -1)
            return dp[idx][k];
        int res = max(events[idx][2] + solve(events, idx + 1, k - 1, events[idx][1]), solve(events, idx + 1, k, end));
        return dp[idx][k] = res;
    }
};