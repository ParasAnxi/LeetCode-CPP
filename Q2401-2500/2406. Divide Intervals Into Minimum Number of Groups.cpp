class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            if (pq.empty() || pq.top() < intervals[i][0])
            {
                if (!pq.empty())
                    pq.pop();
                pq.push(intervals[i][1]);
            }
            else
            {
                pq.push(intervals[i][1]);
            }
        }
        return pq.size();
    }
};