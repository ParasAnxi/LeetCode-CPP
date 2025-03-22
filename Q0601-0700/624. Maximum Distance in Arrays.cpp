class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int mini = arrays[0][0], maxi = arrays[1][arrays[1].size() - 1], ans = 0;
        for (int i = 2; i < arrays.size(); i++)
        {
            int diff = 0, diff1 = 0;
            if (arrays[i][0] < mini)
                diff = abs(mini - arrays[i][0]);
            if (arrays[i][arrays[i].size() - 1] > maxi)
                diff1 = abs(maxi - arrays[i][arrays[i].size() - 1]);
            if (diff > diff1)
                mini = min(mini, arrays[i][0]);
            else
                maxi = max(maxi, arrays[i][arrays[i].size() - 1]);
        }
        ans = abs(mini - maxi);
        mini = arrays[1][0], maxi = arrays[0][arrays[0].size() - 1];
        for (int i = 2; i < arrays.size(); i++)
        {
            int diff = 0, diff1 = 0;
            if (arrays[i][0] < mini)
                diff = abs(mini - arrays[i][0]);
            if (arrays[i][arrays[i].size() - 1] > maxi)
                diff1 = abs(maxi - arrays[i][arrays[i].size() - 1]);
            if (diff > diff1)
                mini = min(mini, arrays[i][0]);
            else
                maxi = max(maxi, arrays[i][arrays[i].size() - 1]);
        }
        return max(ans, abs(mini - maxi));
    }
};