using pii = pair<int,int>;
using umipii = unordered_map<int,pii>;
class NeighborSum {
private:
  umipii mp;

public:
  NeighborSum(vector<vector<int>> &grid) {

    int n = grid.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {

        bool rG = ((i + 1) < n);
        bool bG = ((j + 1) < n);
        bool lG = ((i - 1) >= 0);
        bool tG = ((j - 1) >= 0);

        int adjS = 0;
        if (rG)
          adjS += grid[i + 1][j];
        if (bG)
          adjS += grid[i][j + 1];
        if (lG)
          adjS += grid[i - 1][j];
        if (tG)
          adjS += grid[i][j - 1];

        int dS = 0;
        if (tG && rG)
          dS += grid[i + 1][j - 1];
        if (tG && lG)
          dS += grid[i - 1][j - 1];
        if (bG && rG)
          dS += grid[i + 1][j + 1];
        if (bG && lG)
          dS += grid[i - 1][j + 1];

        mp[grid[i][j]].first = adjS;
        mp[grid[i][j]].second = dS;
      }
    }
  }


  int adjacentSum(int value) { return mp[value].first; }

  int diagonalSum(int value) { return mp[value].second; }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */