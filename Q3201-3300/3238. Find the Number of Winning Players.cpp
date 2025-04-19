class Solution {
public:
  int winningPlayerCount(int m, vector<vector<int>> &pick) {
    int n = 101;
    int ans = 0;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (auto i : pick) v[i[0]][i[1]]++;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (v[i][j] > i) {
          ans++;
          break;
        }
      }
    }
    return ans;
  }
};