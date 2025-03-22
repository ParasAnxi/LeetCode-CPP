class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        int n = timePoints.size();
        vector<int> minutes(n);
        for (int i = 0; i < n; i++)
        {
            string time = timePoints[i];
            string hour = time.substr(0, 2);
            string minute = time.substr(3);
            int hour1 = stoi(hour);
            int minute1 = stoi(minute);
            minutes[i] = 60 * hour1 + minute1;
        }
        sort(minutes.begin(), minutes.end());
        int res = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            res = min(res, minutes[i] - minutes[i - 1]);
        }
        res = min(res, 60 * 24 - minutes[n - 1] + minutes[0]);
        return res;
    }
};