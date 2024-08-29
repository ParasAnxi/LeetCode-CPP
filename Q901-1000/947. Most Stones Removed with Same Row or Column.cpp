class Solution
{
public:
    void isPossible(vector<bool> &visited, vector<vector<int>> &stones, vector<vector<int>> &v, int on)
    {
        if (visited[on])
            return;
        visited[on] = true;
        for (int i : v[on])
        {
            isPossible(visited, stones, v, i);
        }
    }
    int removeStones(vector<vector<int>> &stones)
    {
        vector<vector<int>> v(stones.size(), vector<int>(0));
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = i + 1; j < stones.size(); j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        vector<bool> visited(stones.size(), false);
        int ans = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            if (visited[i])
                continue;
            ans++;
            isPossible(visited, stones, v, i);
        }
        return stones.size() - ans;
    }
};