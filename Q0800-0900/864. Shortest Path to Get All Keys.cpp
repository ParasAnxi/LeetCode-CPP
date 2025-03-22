class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(),m = grid[0].size();
        int x,y;
        int keys = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='@') x = i, y = j;
                if(grid[i][j]>='a' && grid[i][j]<='f') keys++;
            }
        }
        int dir[] = {0,1,0,-1,0};
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>> (m, vector<bool> (64,false)));
        queue<pair<int,pair<int,int>>> q;
        vis[x][y][0] = true;
        q.push({0,{x,y}});
        int count=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int a = q.front().second.first;
                int b = q.front().second.second;
                int carry = q.front().first;
                q.pop();
                if(carry==((1<<keys)-1)) return count;
                for(int i=0; i<4; i++){
                    int c = a + dir[i];
                    int d = b + dir[i+1];
                    int k = carry;
                    if(c>=0 && c<n && d>=0 && d<m && !vis[c][d][k] && grid[c][d]!='#'){
                        if(grid[c][d]>='a' && grid[c][d]<='f'){
                            k = carry|(1<<(grid[c][d]-'a'));
                        }else if(grid[c][d]>='A' && grid[c][d]<='F'){
                            if(!(carry & (1<<(grid[c][d]-'A')))) continue;
                        }
                        vis[c][d][k] = 1;
                        q.push({k,{c,d}});
                    }
                }
            }
            count++;
        }
        return -1;
    }
};