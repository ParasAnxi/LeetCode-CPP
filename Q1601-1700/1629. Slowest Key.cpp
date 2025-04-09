class Solution {
public:
  char slowestKey(vector<int> &rT, string kP) {
    int maxi = rT[0];
    char ans = kP[0];
    for (int i = 1; i < rT.size(); i++) {
      if (maxi < (rT[i] - rT[i - 1])) {
        maxi = rT[i] - rT[i - 1];
        ans = kP[i];
      } else if (maxi == (rT[i] - rT[i - 1])) {
        if (kP[i] > ans) {
          ans = kP[i];
        }
      }
    }
    return ans;
  }
};