class Solution
{
public:
    bool solve(vector<int> &arr, long long k, int ans)
    {
        int n = arr.size();
        long long int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += (arr[i] / ans);
            if (count >= k)
                return true;
        }
        return false;
    }
    int maximumCandies(vector<int> &candies, long long k)
    {
        int n = candies.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, candies[i]);
        }
        int l = 1, r = maxi;
        int ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (solve(candies, k, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};