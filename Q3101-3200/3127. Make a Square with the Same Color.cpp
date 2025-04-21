using vi = vector<int>;
using vvi = vector<vi>;
#define pb push_back
class Solution {
public:
  bool canMakeSquare(vector<vector<char>> &grid) {
    vvi cord{{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    for (auto i : cord) {
      int n = 0;
      for (auto cor : cord) {
        if (grid[i[0] + cor[0]][i[1] + cor[1]] == 'W') {
          n++;
        }
      }
      if (n != 2) {
        return 1;
      }
    }
    return 0;
  }
};