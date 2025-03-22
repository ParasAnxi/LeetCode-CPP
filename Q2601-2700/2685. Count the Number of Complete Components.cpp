class Solution
{
public:
    vector<int> parent, rank, edge;
    int find(int x){
        if (x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y){
        int parentX = find(x);
        int parentY = find(y);

        if (parentX == parentY){
            edge[parentX]++;
            return;
        }

        if (rank[parentX] > rank[parentY]){
            parent[parentY] = parentX;
            edge[parentX] += edge[parentY] + 1;
        }
        else if (rank[parentX] < rank[parentY]){
            parent[parentX] = parentY;
            edge[parentY] += edge[parentX] + 1;
        }
        else{
            parent[parentY] = parentX;
            rank[parentX]++;
            edge[parentX] += edge[parentY] + 1;
        }
    }

    int countCompleteComponents(int n, vector<vector<int>> &edges){
        parent.resize(n);
        rank.resize(n, 0);
        edge.resize(n, 0);

        for (int i = 0; i < n; i++){
            parent[i] = i;
        }

        for (auto &it : edges){
            int u = it[0], v = it[1];
            Union(u, v);
        }

        int count = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[find(i)]++;
        }

        for (auto &it : mp){
            int node = it.first;
            int size = it.second;
            if (edge[node] == (size * (size - 1)) / 2)
            {
                count++;
            }
        }

        return count;
    }
};