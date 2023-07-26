class Solution
{
public:
    bool solve(vector<int> &dist, int speed, double hour)
    {
        double ans = 0;
        int n = dist.size();
        for (int i = 0; i < n; i++)
        {
            double time = dist[i] * 1.0 / speed;
            if (i != n - 1)
            {
                ans = ans + ceil(time);
            }
            else
            {
                ans += time;
            }
            if (ans > hour)
            {
                return false;
            }
        }
        return true;
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int start = 1;
        int end = 1e7;
        int minspeed = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (solve(dist, mid, hour))
            {
                minspeed = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return minspeed;
    }
};