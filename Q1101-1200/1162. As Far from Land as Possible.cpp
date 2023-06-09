class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }
        int res = 0;
        while(!q.empty()){
            res++;
            int qs = q.size();
            vector<vector<int>> path = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
            for(int i=0;i<qs;i++){
                pair<int, int> top = q.front();
                q.pop();
                for(auto it:path){
                    int x = top.first + it[0], y = top.second + it[1];
                    if(0 <= x && x < n && 0 <= y && y < n && grid[x][y] == 0){
                        grid[x][y] = res;
                        q.push({x, y});
                    }
                }
            }
        }
        return res == 1 ? -1 : res-1;
    }
};