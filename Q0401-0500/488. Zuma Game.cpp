class Solution {
public:
  string updateBoard(string board) {
    int s = 0;
    int e = 0;
    int n = board.length();
    while (s < n) {
      while (e < n && board[s] == board[e]) {
        e++;
      }
      if (e - s >= 3) {
        string nB = board.substr(0, s) + board.substr(e);
        return updateBoard(nB);
      } else {
        s = e;
      }
    }
    return board;
  }

  string solveS(vector<int> &vF) {
    string st = "";
    for (int i = 0; i < vF.size(); i++) {
      if (vF[i] > 0)
        st += to_string((char)i + 'A') + to_string(vF[i]);
    }
    return st;
  }
  int solve(string board, vector<int> &vF, unordered_map<string, int> &mp) {
    string st = board + "#" + solveS(vF);
    if (mp.count(st)) {
      return mp[st];
    }
    int e = INT_MAX;
    if (board.length() == 0) {
      e = 0;
    } else {
      for (int i = 0; i < board.length(); i++) {
        for (int j = 0; j < vF.size(); j++) {
          bool flg = 0;
          if (board[i] - 'A' == j)
            flg = 1;
          else if (i > 0 && board[i] == board[i - 1] && board[i] - 'A' != j)
            flg = 1;
          if (vF[j] > 0 && flg) {
            board.insert(board.begin() + i, j + 'A');
            vF[j]--;
            string str = updateBoard(board);
            int sS = solve(str, vF, mp);
            if (sS != -1) {
              e = min(e, sS + 1);
            }
            vF[j]++;
            board.erase(board.begin() + i);
          }
        }
      }
    }
    if (e == INT_MAX)
      e = -1;
    mp[st] = e;
    return e;
  }
  int findMinStep(string board, string hand) {
    vector<int> vF(26, 0);
    for (char c : hand)
      vF[c - 'A']++;
    unordered_map<string, int> mp;
    return solve(board, vF, mp);
  }
};