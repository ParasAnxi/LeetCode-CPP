class Solution
{
public:
    bool isPossible(vector<int> &batteries, long long mid, int numOfComputer)
    {
        long long sum = 0;
        for (int i = batteries.size() - 1; i >= 0; i--)
        {
            sum += batteries[i] >= mid ? mid : batteries[i];
        }
        return sum / numOfComputer >= mid;
    }
    long long maxRunTime(int n, vector<int> &batteries)
    {
        long long ans = 0;
        long long low = 0;
        long long high = 1e14;
        sort(batteries.begin(), batteries.end());
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (isPossible(batteries, mid, n))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};