class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int ans = 0;
        vector<int> v(arr.size());
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == 0)
            {
                v[i] = arr[i];
            }
            else
            {
                v[i] = v[i - 1] + arr[i];
            }
            if (v[i] == i * (i + 1) / 2)
                ans++;
        }
        return ans;
    }
};