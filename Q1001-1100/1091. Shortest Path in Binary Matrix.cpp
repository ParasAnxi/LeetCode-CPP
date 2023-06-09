class Solution {
public:
    vector<pair<int,int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == 1 or grid[m-1][n-1] == 1) return -1;
        grid[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            if(x == m-1 and y == n-1) return grid[x][y];
            for(auto [x1, y1] : direction){
                int newX = x + x1;
                int newY = y + y1;
                if(newX >= 0 and newX < m and newY >= 0 and newY < n and grid[newX][newY] == 0){
                    grid[newX][newY] = grid[x][y]+1;
                    q.push({newX, newY});
                }
            }
        }
        return -1;
    }
};