class Solution
{
public:
    int check(vector<int> arr, int k, int p)
    {
        int i = 1;
        while (i < arr.size() && p > 0)
        {
            if (arr[i] - arr[i - 1] <= k)
            {
                p -= 1;
                i += 2;
            }
            else
                i++;
        }
        return p <= 0;
    }
    int minimizeMax(vector<int> &arr, int p)
    {
        sort(arr.begin(), arr.end());
        int start = 0, end = arr[arr.size() - 1] - arr[0], ans = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (check(arr, mid, p))
            {
                end = mid - 1;
                ans = mid;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};