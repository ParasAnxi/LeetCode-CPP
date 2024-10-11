class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int index = times[targetFriend][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<int, vector<int>, greater<int>> chairs;
        sort(times.begin(), times.end());
        for (int i = 0; i < times.size(); i++)
        {
            chairs.push(i);
        }
        for (int i = 0; i < times.size(); i++)
        {
            while (!pq.empty() && pq.top().first <= times[i][0])
            {
                chairs.push(pq.top().second);
                pq.pop();
            }
            int chair = chairs.top();
            chairs.pop();
            if (times[i][0] == index)
                return chair;
            pq.push({times[i][1], chair});
        }
        return -1;
    }
};