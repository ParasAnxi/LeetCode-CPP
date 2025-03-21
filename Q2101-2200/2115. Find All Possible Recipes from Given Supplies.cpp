class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        unordered_map<string, int> inDeg;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> avlSup(supplies.begin(), supplies.end());
        queue<string> q;
        vector<string> result;

        for (int i = 0; i < recipes.size(); i++)
        {
            string recipe = recipes[i];
            inDeg[recipe] = ingredients[i].size();
            for (auto &ingredient : ingredients[i])
            {
                graph[ingredient].push_back(recipe);
            }
        }

        for (auto &supply : supplies)
        {
            q.push(supply);
        }

        while (!q.empty())
        {
            string front = q.front();
            q.pop();

            if (inDeg.count(front))
            {
                result.push_back(front);
            }

            for (auto &recipe : graph[front])
            {
                inDeg[recipe]--;
                if (inDeg[recipe] == 0)
                {
                    q.push(recipe);
                }
            }
        }
        return result;
    }
};