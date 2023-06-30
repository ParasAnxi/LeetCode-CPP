class Solution {
private:
    bool bfs(vector<vector<int>> &grid){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n));
        for(int i=0;i<n;i++)
            if(!grid[0][i]) q.push({0,i}), vis[0][i] = true;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto [i,j] = q.front(); q.pop();
                if(i == m-1)
                 return true;
                if(i-1 >= 0 and !vis[i-1][j] and !grid[i-1][j]) 
                    vis[i-1][j] = true, q.push({i-1,j});
                if(i+1 < m and !vis[i+1][j] and !grid[i+1][j])
                    vis[i+1][j] = true, q.push({i+1,j});
                if(j-1 >= 0 and !vis[i][j-1] and !grid[i][j-1])
                    vis[i][j-1] = true, q.push({i,j-1});
                if(j+1 < n and !vis[i][j+1] and !grid[i][j+1])
                    vis[i][j+1] = true, q.push({i,j+1});
            }
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int> (col));
        int low = 0, high = cells.size()-1, ans = 0, x = 0;
        int mid = cells.size()-1;
        while(low <= high){
            int mid = (low + high)/2;
            while(x <= mid){
                grid[cells[x][0]-1][cells[x][1]-1] = 1;
                x++;
            }
            bool res = bfs(grid);
            if(res){
                ans = mid+1;
                low = mid+1;
            }else{
                while(x > low){
                    x--;
                    grid[cells[x][0]-1][cells[x][1]-1] = 0;
                }
                grid[cells[x][0]-1][cells[x][1]-1] = 0;
                high = mid-1;
            }
        }
        return ans;
    }
};