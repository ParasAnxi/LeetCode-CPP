using ll = long long;
using ull = unsigned long long;
using ld = long double;
using cd = complex<double>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using pll = pair<ll, ll>;
using ppii = pair<int, pii>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using pis = pair<int, string>;
using vs = vector<string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using umii = unordered_map<int, int>;
using umcvi = unordered_map<char, vi>;
using umci = unordered_map<char, int>;
#define pb push_back
#define MOD 1000000007
#define LMOD 1000000000000000007LL
class Solution {
public:
  bool check(int x, int y, int m, int n) {
    return x >= 0 && y >= 0 && x < m && y < n;
  }

  void solve(int i, int j, vector<vc> &board, int m, int n,vector<int> &dX, vector<int> &dY) {
    if (board[i][j] == 'M') {
      board[i][j] = 'X';
      return;
    }
    int rev = 0;
    for (int k = 0; k < 8; k++) {
      int x = i + dX[k], y = j + dY[k];
      if (check(x, y, m, n) && board[x][y] == 'M')
        rev++;
    }
    if (rev > 0) {
      board[i][j] = rev + '0';
    } else {
      board[i][j] = 'B';
      for (int k = 0; k < 8; k++) {
        int x = i + dX[k], y = j + dY[k];
        if (check(x, y, m, n) && board[x][y] == 'E') {
          solve(x, y, board, m, n, dX, dY);
        }
      }
    }
  }

  vector<vector<char>> updateBoard(vector<vector<char>> &board,vector<int> &click) {
    int m = board.size();
    int n = board[0].size();
    vi dX = {0, 1, 0, -1, 1, 1, -1, -1};
    vi dY = {1, 0, -1, 0, 1, -1, 1, -1};
    solve(click[0], click[1], board, m, n, dX, dY);
    return board;
  }
};
