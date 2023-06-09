class Solution {
public:
    bool ok(vector<vector<int>>& grid , int i , int j , int n , int m){
        return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != 1);
    }
    void dfs(vector<vector<int>>& grid, int i , int j , int n , int m){
        if(!ok(grid , i , j , n , m)){
            return ;
        }
        grid[i][j] = 1;
        dfs(grid , i + 1 , j , n , m);
        dfs(grid , i - 1 , j , n , m);
        dfs(grid , i , j + 1 , n , m);
        dfs(grid , i , j - 1 , n , m);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < m ; i++){
            if(grid[0][i] == 0){
                dfs(grid , 0 , i , n , m);
            }
            if(grid[n-1][i] == 0){
                dfs(grid , n-1 , i , n , m);
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(grid[i][0] == 0){
                dfs(grid , i , 0 , n , m);
            }
            if(grid[i][m-1] == 0){
                dfs(grid , i , m-1 , n , m);
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0){
                    dfs(grid , i , j , n , m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};