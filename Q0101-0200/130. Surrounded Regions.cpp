class Solution {
public:
  void solve1(int row, int col, int dirR[], int dirC[],
              vector<vector<int>> &visited, vector<vector<char>> &board) {
    visited[row][col] = 1;
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < 4; i++) {
      int nrow = row + dirR[i];
      int ncol = col + dirC[i];
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
          !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
        solve1(nrow, ncol, dirR, dirC, visited, board);
      }
    }
  }
  void solve(vector<vector<char>> &board) {
    int n = board.size();
    int m = board[0].size();

    int dirR[] = {-1, 1, 0, 0};
    int dirC[] = {0, 0, -1, 1};
    vector<vector<int>> visited(n, vector<int>(m));
    for (int j = 0; j < m; j++) {
      if (!visited[0][j] && board[0][j] == 'O') {
        solve1(0, j, dirR, dirC, visited, board);
      }
      if (!visited[n - 1][j] && board[n - 1][j] == 'O') {
        solve1(n - 1, j, dirR, dirC, visited, board);
      }
    }
    for (int i = 0; i < n; i++) {
      if (!visited[i][0] && board[i][0] == 'O') {
        solve1(i, 0, dirR, dirC, visited, board);
      }
      if (!visited[i][m - 1] && board[i][m - 1] == 'O') {
        solve1(i, m - 1, dirR, dirC, visited, board);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};