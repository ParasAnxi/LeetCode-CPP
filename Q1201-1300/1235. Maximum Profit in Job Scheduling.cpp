class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<pair<int, pair<int, int>>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i].first = endTime[i];
            v[i].second.first = startTime[i];
            v[i].second.second = profit[i];
        }

        sort(v.begin(), v.end());

        vector<int> dp(n);
        dp[0] = v[0].second.second;

        for (int i = 1; i < n; i++)
        {
            int f = 0;
            int s = 0, e = i - 1;
            while (s <= e)
            {
                int mid = s +(e-s) / 2;
                if (v[mid].first <= v[i].second.first)
                {
                    f = dp[mid];
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            dp[i] = max(dp[i - 1], f + v[i].second.second);
        }

        return dp[n - 1];
    }
};