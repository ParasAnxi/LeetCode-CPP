class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int ans = 0;
        int n = colors.size();
        int ind = 0;
        while (ind < n)
        {
            int j = ind + 1;
            int maxi = neededTime[ind];
            int sum = neededTime[ind];
            while (j < n && colors[j] == colors[ind])
            {
                maxi = max(neededTime[j], maxi);
                sum += neededTime[j];
                j++;
            }
            ans += (sum - maxi);
            ind = j;
        }
        return ans;
    }
};