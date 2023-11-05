class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int s = 0;
        int e = 0;
        for (int i = 0; e < arr.size(); ++i)
        {
            if (i == arr.size())
                i = 0;
            if (s == i)
                continue;
            if (arr[s] > arr[i])
                ++e;
            else
            {
                s = i;
                e = 1;
            }
            if (e == k || e > arr.size())
                return arr[s];
        }
        return arr[s];
    }
};