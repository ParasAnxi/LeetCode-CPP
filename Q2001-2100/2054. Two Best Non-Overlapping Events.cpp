class Solution
{
public:
    int bs(int i, vector<vector<int>> &events, int n)
    {
        int left = i + 1;
        int right = n - 1;
        int mid;
        int index = -1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (events[mid][0] > events[i][1])
            {
                index = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return index;
    }

    int maxTwoEvents(vector<vector<int>> &events)
    {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int> v(n, INT_MIN);
        int maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            maxi = max(maxi, events[i][2]);
            v[i] = maxi;
        }
        int ans = 0;
        int index;
        for (int i = 0; i < n; i++)
        {
            index = bs(i, events, n);
            int val = events[i][2];
            if (index != -1)
                val += v[index];
            ans = max(ans, val);
        }
        return ans;
    }
};
