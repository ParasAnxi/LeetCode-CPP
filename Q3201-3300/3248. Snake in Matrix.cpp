class Solution {
public:
  int finalPositionOfSnake(int n, vector<string> &commands) {
    int ans = 0;
    for (auto &i : commands) {
      if (i == "UP")
        ans -= n;
      if (i == "DOWN")
        ans += n;
      if (i == "LEFT")
        ans--;
      if (i == "RIGHT")
        ans++;
    }
    return ans;
  }
};