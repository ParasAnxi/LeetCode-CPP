class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<int> indegree(numCourses, 0);

        vector<int> adj[numCourses];
        for (auto &it : prerequisites)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<unordered_set<int>> dep(numCourses);
        vector<bool> ans;
        queue<int> q;

        for (int node = 0; node < numCourses; node++)
        {
            if (indegree[node] == 0)
            {
                q.push(node);
                dep[node].insert(-1);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &nbr : adj[node])
            {
                dep[nbr].insert(node);
                for (auto &it : dep[node])
                {
                    dep[nbr].insert(it);
                }

                indegree[nbr]--;

                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        for (auto &qry : queries)
        {
            int u = qry[0];
            int v = qry[1];

            if (dep[v].count(u))
            {
                ans.push_back(true);
            }
            else
                ans.push_back(false);
        }

        return ans;
    }
};