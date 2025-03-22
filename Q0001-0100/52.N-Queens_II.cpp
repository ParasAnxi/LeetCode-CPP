class Solution
{
public:
    bool isSafe(int row, int col, vector<string> board)
    {
        int x = row;
        int y = col;
        // row check
        while (y >= 0)
        {
            if (board[x][y] == 'Q')
            {
                return false;
            }
            y--;
        }
        x = row;
        y = col;
        // upper diagonal check
        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 'Q')
            {
                return false;
            }
            x--;
            y--;
        }
        x = row;
        y = col;
        // lower diagonal check
        while (x < board.size() && y >= 0)
        {
            if (board[x][y] == 'Q')
            {
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    int solve(int col, vector<string> &board)
    {
        if (col == board.size())
        {
            return 1;
        }
        int count = 0;
        for (int row = 0; row < board.size(); row++)
        {
            if (isSafe(row, col, board))
            {
                board[row][col] = 'Q';
                count += solve(col + 1, board);
                board[row][col] = '.';
            }
        }
        return count;
    }
    int totalNQueens(int n)
    {
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        return solve(0, board);
    }
};