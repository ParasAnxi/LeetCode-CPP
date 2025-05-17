class NumMatrix {
public:
  vector<vector<int>> v;
  NumMatrix(vector<vector<int>> &matrix) {
    for (int r = 0; r < matrix.size(); ++r) {
      for (int c = 0; c < matrix[0].size(); ++c) {
        int top = r == 0 ? 0 : matrix[r - 1][c];
        int left = c == 0 ? 0 : matrix[r][c - 1];
        int tL = (r == 0 || c == 0) ? 0 : matrix[r - 1][c - 1];
        matrix[r][c] += top + left - tL;
      }
    }
    v = matrix;
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int tR = row1 > 0 ? v[row1 - 1][col2] : 0;
    int bL = col1 > 0 ? v[row2][col1 - 1] : 0;
    int tL = (row1 == 0 || col1 == 0) ? 0 : v[row1 - 1][col1 - 1];
    return v[row2][col2] - tR - bL + tL;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */