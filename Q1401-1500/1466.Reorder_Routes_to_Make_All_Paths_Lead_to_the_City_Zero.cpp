class Solution {
    int dfs(int Node, int pnt, vector<pair<int, int>> ar[]) {
        int cnt = 0;
        for(auto a : ar[Node]) {
            if(a.first == pnt) continue;
            cnt += a.second + dfs(a.first, Node, ar);
        }
        return cnt;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> ar[n];
        for(auto i : connections) {
            ar[i[0]].push_back({i[1], 1});
            ar[i[1]].push_back({i[0], 0});
        }
        return dfs(0, -1, ar);
    }
};