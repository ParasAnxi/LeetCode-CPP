class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < m; j++) {
        matrix[i][j] += matrix[i][j - 1];
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = i; j < m; j++) {
        set<int> st{0};
        int currS = 0;
        for (int row = 0; row < n; row++) {
          int sum = matrix[row][j];
          if (i > 0)
            sum -= matrix[row][i - 1];
          currS += sum;
          auto it = st.lower_bound(currS - k);
          if (it != st.end())
            ans = max(ans, currS - *it);
          st.insert(currS);
        }
      }
    }
    return ans;
  }
};