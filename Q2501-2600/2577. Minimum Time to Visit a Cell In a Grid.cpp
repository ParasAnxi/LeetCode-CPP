class Solution
{
public:
    int minimumTime(vector<vector<int>> &grid)
    {
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        priority_queue<pair<int, pair<int, int>>> pq;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));

        time[0][0] = 0;
        pq.push({0, {0, 0}});

        auto isOut = [&](int row, int col)
        {
            return row < 0 || col < 0 || row >= n || col >= m;
        };

        auto isSafe = [&](int row, int col, int currT)
        {
            for (int i = 0; i < 4; i++)
            {
                int newR = row + dir[i].first;
                int newC = col + dir[i].second;
                if (isOut(newR, newC))
                    continue;
                if (currT + 1 < grid[newR][newC])
                    continue;
                return true;
            }
            return false;
        };

        while (!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            int currTime = -f.first;
            int currRow = f.second.first;
            int currCol = f.second.second;
            for (int i = 0; i < 4; i++)
            {
                int newRow = currRow + dir[i].first;
                int newCol = currCol + dir[i].second;
                if (isOut(newRow, newCol))
                    continue;
                int timeToVisit = currTime + 1;
                if (timeToVisit < grid[newRow][newCol])
                {
                    if (!isSafe(currRow, currCol, currTime))
                        continue;
                    timeToVisit = grid[newRow][newCol] + ((grid[newRow][newCol] - timeToVisit) % 2);
                }
                if (timeToVisit < time[newRow][newCol])
                {
                    time[newRow][newCol] = timeToVisit;
                    pq.push({-timeToVisit, {newRow, newCol}});
                }
            }
        }

        return time[n - 1][m - 1] == INT_MAX ? -1 : time[n - 1][m - 1];
    }
};