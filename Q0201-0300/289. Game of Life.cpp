class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    int n = board.size();
    int m = n ? board[0].size() : 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int count = 0;
        for (int r = max(0, i - 1); r < min(n, i + 2); r++) {
          for (int c = max(0, j - 1); c < min(m, j + 2); c++) {
            count += board[r][c] & 1;
          }
        }
        if (count == 3 || count - board[i][j] == 3) {
          board[i][j] |= 2;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        board[i][j] >>= 1;
      }
    }
  }
};