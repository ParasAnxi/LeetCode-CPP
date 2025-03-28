class Solution
{
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int m = grid.size();
        int n = grid[0].size();
        int k = queries.size();
        vector<int> ans(k, 0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> cords = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<pair<int, int>> sQ;
        for (int i = 0; i < k; i++)
        {
            sQ.push_back({queries[i], i});
        }
        sort(sQ.begin(), sQ.end());

        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<>>pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int count = 0;
        for (auto &q : sQ){
            int val = q.first, index = q.second;
            while (!pq.empty() && pq.top().first < val){
                auto [value, cell] = pq.top();
                pq.pop();
                int x = cell.first;
                int y = cell.second;
                count++;

                for (auto &dir : cords){
                    int nX = x + dir.first, nY = y + dir.second;
                    if (nX >= 0 && nY >= 0 && nX < m && nY < n && !visited[nX][nY]){
                        pq.push({grid[nX][nY], {nX, nY}});
                        visited[nX][nY] = true;
                    }
                }
            }
            ans[index] = count;
        }

        return ans;
    }
};