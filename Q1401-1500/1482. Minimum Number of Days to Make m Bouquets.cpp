class Solution
{
public:
    bool isPossible(vector<int> bloomDay, int mid, int m, int k)
    {
        int ind = 0;
        for (auto i : bloomDay)
        {
            if (mid >= i)
            {
                ind++;
                if (ind == k)
                {
                    m--;
                    ind = 0;
                    if (m == 0)
                        return true;
                }
            }
            else
                ind = 0;
        }
        if (m == 0)
            return true;
        else
            return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long total = (long)m * (long)k;
        if (total > bloomDay.size())
            return -1;
        int max = *max_element(bloomDay.begin(), bloomDay.end());
        int min = *min_element(bloomDay.begin(), bloomDay.end());
        int low = min;
        int high = max;
        int mid;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (!isPossible(bloomDay, mid, m, k))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};