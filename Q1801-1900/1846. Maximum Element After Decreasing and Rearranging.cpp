class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int prev = 1;
        for (int i = 0; i < n; i++)
        {
            int curr = min(arr[i], prev);
            prev = curr + 1;
        }
        return prev - 1;
    }
};