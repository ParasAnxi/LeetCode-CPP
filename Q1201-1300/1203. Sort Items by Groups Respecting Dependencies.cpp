class Solution{
    bool topoSort(unordered_map<int, unordered_set<int>> &graph, vector<int> &output){
        unordered_map<int, int> inDegree;
        queue<int> q;

        for (auto &it : graph){
            inDegree[it.first];
            for (int nei : it.second)
                ++inDegree[nei];
        }

        for (auto &it : inDegree)
            if (!it.second)
                q.push(it.first);

        vector<int> ordering;
        int count = 0;
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            output[count++] = cur;
            for (int nei : graph[cur])
                if (--inDegree[nei] == 0)
                    q.push(nei);
        }

        return count == graph.size();
    }

public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems){
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i){
            if (group[i] == -1)
                group[i] = m++;
            mp[group[i]].push_back(i);
        }

        for (auto &it : mp){
            unordered_map<int, unordered_set<int>> graph;
            for (int item : it.second){
                graph[item];
                for (int prereq : beforeItems[item])
                    if (group[prereq] == group[item])
                        graph[prereq].insert(item);
            }

            if (!topoSort(graph, it.second))
                return {};
        }
        unordered_map<int, unordered_set<int>> um;
        for (int i = 0; i < m; ++i)
            um[i];
        for (int i = 0; i < n; ++i)
            for (int prereq : beforeItems[i])
                if (group[prereq] != group[i] && !um[group[prereq]].count(group[i]))
                    um[group[prereq]].insert(group[i]);
        vector<int> ordering(m);
        if (!topoSort(um, ordering))
            return {};
        vector<int> res;
        for (int group : ordering)
            copy(mp[group].begin(), mp[group].end(), back_inserter(res));
        return res;
    }
};