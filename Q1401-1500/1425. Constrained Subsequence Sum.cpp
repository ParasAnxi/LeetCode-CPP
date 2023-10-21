class Solution
{
public:
    int constrainedSubsetSum(vector<int> &a, int k)
    {
        int n = a.size();
        vector<int> dp(n, 0);
        deque<int> dq;
        dp[n - 1] = a[n - 1];
        dq.push_back(n - 1);

        for (int i = n - 2; i >= 0; i--)
        {
            if (dq.front() - i > k)
                dq.pop_front();
            dp[i] += a[i];
            dp[i] += dp[dq.front()];
            dp[i] = max(a[i], dp[i]);
            while (!dq.empty() and dp[i] > dp[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};