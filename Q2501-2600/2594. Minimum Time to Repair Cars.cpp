class Solution
{
public:
    bool check(vector<int> &ranks, long long mid, int cars)
    {
        int n = ranks.size();
        long long count = 0;
        for (int i = 0; i < n; i++)
        {
            if (mid >= ranks[i]) count = count + (long long)sqrt((double)mid / ranks[i]);
        }
        if (count >= cars)
            return true;
        else
            return false;
    }

    long long repairCars(vector<int> &ranks, int cars)
    {
        int n = ranks.size();
        long long s = 1;
        long long ans = 0;
        long long e = (long long)*max_element(ranks.begin(), ranks.end()) * (long long)cars * (long long)cars;

        while (s <= e)
        {
            long long mid = (e + s) / 2;
            if (check(ranks, mid, cars))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};