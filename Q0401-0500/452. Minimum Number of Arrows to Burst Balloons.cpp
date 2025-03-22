class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 1)
        {
            return 1;
        }
        sort(points.begin(), points.end());
        int count = 1;
        int r = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (r >= points[i][0])
            {
                r = min(points[i][1], r);
            }
            else
            {
                r = points[i][1];
                count++;
            }
        }
        return count;
    }
};