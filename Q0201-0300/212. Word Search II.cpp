class Node {
public:
  vector<Node *> childs = vector<Node *>(26, NULL);
  int isTerminal = 0;
};

class Trie {
public:
  Node *root = new Node();

  void insert(const string &s) {
    auto curr = root;
    for (char ch : s) {
      int idx = ch - 'a';
      if (curr->childs[idx] == NULL) {
        curr->childs[idx] = new Node();
      }
      curr = curr->childs[idx];
    }
    curr->isTerminal = 1;
  }

  int search(const string &word) {
    auto curr = root;
    for (char ch : word) {
      int idx = ch - 'a';
      if (curr->childs[idx] == NULL) {
        return 0;
      }
      curr = curr->childs[idx];
    }
    return curr->isTerminal;
  }

  int startsWith(const string &prefix) {
    auto curr = root;
    for (char ch : prefix) {
      int idx = ch - 'a';
      if (curr->childs[idx] == NULL) {
        return 0;
      }
      curr = curr->childs[idx];
    }
    return 1;
  }
};

class Solution {
public:
  Trie t;
  vector<int> dX = {0, 0, 1, -1};
  vector<int> dY = {-1, 1, 0, 0};
  vector<string> ans;
  unordered_set<string> fnd;

  int chk(int x, int y, vector<vector<char>> &board,
          vector<vector<int>> &visited) {
    int n = board.size(), m = board[0].size();
    return (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]);
  }

  void solve(vector<vector<char>> &board, int i, int j, string &s,
             vector<vector<int>> &visited) {
    if (!t.startsWith(s))
      return;
    if (t.search(s) && fnd.find(s) == fnd.end()) {
      ans.push_back(s);
      fnd.insert(s);
    }
    visited[i][j] = 1;
    for (int k = 0; k < 4; ++k) {
      int nI = i + dX[k], nJ = j + dY[k];
      if (chk(nI, nJ, board, visited)) {
        s.push_back(board[nI][nJ]);
        solve(board, nI, nJ, s, visited);
        s.pop_back();
      }
    }
    visited[i][j] = 0;
  }

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    for (auto &i : words) {
      t.insert(i);
    }

    int n = board.size(), m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        string s;
        s.push_back(board[i][j]);
        solve(board, i, j, s, visited);
      }
    }
    return ans;
  }
};
