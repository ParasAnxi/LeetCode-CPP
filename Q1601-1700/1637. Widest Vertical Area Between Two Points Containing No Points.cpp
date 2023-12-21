class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        int n = points.size();
        sort(points.begin(), points.end());
        int area = 0;
        for (int i = 1; i < n; i++)
        {
            int curr = points[i][0] - points[i - 1][0];
            area = max(area, curr);
        }
        return area;
    }
};