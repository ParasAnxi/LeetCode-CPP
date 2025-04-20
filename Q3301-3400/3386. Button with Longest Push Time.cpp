class Solution {
public:
  int buttonWithLongestTime(vector<vector<int>> &events) {
    int n = events.size();
    int maxi = events[0][1];
    int ans = events[0][0];

    for (int i = 1; i < n; i++) {
      int currB = events[i][0];
      int currI = events[i][1] - events[i - 1][1];
      if (currI > maxi || currI == maxi && currB < ans) {
        maxi = currI;
        ans = currB;
      }
    }
    return ans;
  }
};