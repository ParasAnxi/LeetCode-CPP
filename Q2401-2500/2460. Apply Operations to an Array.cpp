class Solution
{
public:
    vector<int> applyOperations(vector<int> &arr)
    {
        int n = arr.size();
        vector<int>ans;
        int i = 0;
        int j = i + 1;

        while (j < n)
        {
            if (arr[j] == arr[i])
            {
                arr[i] = 2 * arr[i];
                arr[j] = 0;
            }
            i++;
            j++;
        }
        for (int num : arr)
        {
            if (num != 0) ans.push_back(num);
        }
        while (ans.size() < n)
        {
            ans.push_back(0);
        }

        return ans;
    }
};