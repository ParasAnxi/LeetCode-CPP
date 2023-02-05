// Using recursion
class Solution
{
private:
    int search(vector<int> &arr, int start, int end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        if (arr[mid] < arr[mid + 1])
        {
            return search(arr, mid + 1, end);
        }
        else
        {
            return search(arr, start, mid);
        }
    }

public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int ans = search(arr, 0, arr.size() - 1);
        return ans;
    }
};