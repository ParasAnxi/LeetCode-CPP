class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            int a = abs(points[i][0] - points[i - 1][0]);
            int b = abs(points[i][1] - points[i - 1][1]);
            ans = ans + max(a, b);
        }
        return ans;
    }
};