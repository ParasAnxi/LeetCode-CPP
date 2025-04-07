class Solution {
public:
  int numRookCaptures(vector<vector<char>> &board) {
    int x = -1;
    int y = -1;
    int count = 0;
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        if (board[i][j] == 'R') {
          x = i;
          y = j;
          break;
        }
      }
    }
    for (int i = x; i >= 0; --i) {
      if (board[i][y] == 'B') {
        break;
      } else if (board[i][y] == 'p') {
        count += 1;
        break;
      }
    }
    for (int i = x; i < 8; ++i) {
      if (board[i][y] == 'B') {
        break;
      } else if (board[i][y] == 'p') {
        count += 1;
        break;
      }
    }
    for (int j = y; j >= 0; --j) {
      if (board[x][j] == 'B') {
        break;
      } else if (board[x][j] == 'p') {
        count += 1;
        break;
      }
    }
    for (int j = y; j < 8; ++j) {
      if (board[x][j] == 'B') {
        break;
      } else if (board[x][j] == 'p') {
        count += 1;
        break;
      }
    }
    return count;
  }
};