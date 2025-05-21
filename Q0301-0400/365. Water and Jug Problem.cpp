class Solution {
public:
  bool canMeasureWater(int x, int y, int target) {
    if (target > x + y) {
      return 0;
    }
    if (target == 0) {
      return 1;
    }
    if (x == 0) {
      return y == target;
    }
    if (y == 0) {
      return x == target;
    }
    queue<pair<int, int>> q;
    set<pair<int, int>> st;
    q.push({0, 0});
    st.insert({0, 0});
    while (!q.empty()) {
      auto [dX, dY] = q.front();
      q.pop();
      if (dX + dY == target) {
        return 1;
      }
      vector<pair<int, int>> dirs = {
          {x, dY},
          {dX, y},
          {0, dY},
          {dX, 0},
          {dX - min(dX, y - dY), dY + min(dX, y - dY)},
          {dX + min(dY, x - dX), dY - min(dY, x - dX)}};
      for (auto [nX, nY] : dirs) {
        if (st.count({nX, nY}) == 0) {
          st.insert({nX, nY});
          q.push({nX, nY});
        }
      }
    }
    return 0;
  }
};