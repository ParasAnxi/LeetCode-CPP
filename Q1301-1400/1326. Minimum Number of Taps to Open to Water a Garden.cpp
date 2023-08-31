class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        int count = 0;
        int mini = 0, maxi = 0;
        while (maxi < n)
        {
            for (int i = 0; i < ranges.size(); i++)
            {
                if (mini >= (i - ranges[i]) && mini <= (i + ranges[i]))
                    maxi = max(maxi, i + ranges[i]);
            }
            if (mini == maxi)
                return -1;
            mini = maxi;
            count++;
        }
        return count;
    }
};