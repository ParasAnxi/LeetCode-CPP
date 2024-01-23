class Solution
{
public:
    int solve(vector<string> &arr, int index, vector<int> v)
    {
        if (index >= arr.size())
            return 0;
        int include = 0, exclude = 0;
        exclude = 0 + solve(arr, index + 1, v);
        string temp = arr[index];
        int flag = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            if (v[temp[i] - 'a'] != 0)
            {
                flag = 1;
                break;
            }
            v[temp[i] - 'a']++;
        }
        if (flag != 1)
        {
            include += temp.size() + solve(arr, index + 1, v);
        }
        return max(include, exclude);
    }
    int maxLength(vector<string> &arr)
    {
        vector<int> v(26, 0);
        return solve(arr, 0, v);
    }
};