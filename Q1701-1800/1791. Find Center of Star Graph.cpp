class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int x = edges[0][0];
        int y = edges[0][1];
        if (x == edges[1][0] || x == edges[1][1])
        {
            return x;
        }
        else
        {
            return y;
        }
    }
};