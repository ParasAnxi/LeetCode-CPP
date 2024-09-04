class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int index = 0;
        int x = 0, y = 0;
        int ans = 0;

        set<pair<int, int>> obstacle;
        for (auto &it : obstacles)
        {
            obstacle.insert({it[0], it[1]});
        }

        for (auto it : commands)
        {
            if (it == -1)
                index = (index + 1) % 4;
            else if (it == -2)
                index = (index + 3) % 4;

            else
            {
                int dx = dir[index].first;
                int dy = dir[index].second;

                for (int i = 0; i < it; i++)
                {
                    if (obstacle.find({x + dx, y + dy}) == obstacle.end())
                    {
                        x = x + dx;
                        y = y + dy;
                    }
                    else
                        break;
                }
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};