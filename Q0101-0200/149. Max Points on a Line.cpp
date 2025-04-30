class Solution {
public:
  int maxPoints(vector<vector<int>> &points) {
    int n = points.size();
    if (n <= 1)
      return n;

    int maxi = 1;

    for (int i = 0; i < n; i++) {
      unordered_map<string, int> mp;
      int dup = 1, curMaxi = 0;
      for (int j = i + 1; j < n; j++) {
        int dX = points[j][0] - points[i][0];
        int dY = points[j][1] - points[i][1];
        if (dX == 0 && dY == 0) {
          dup++;
          continue;
        }
        int gcD = __gcd(dX, dY);
        dX /= gcD;
        dY /= gcD;

        string str = to_string(dY) + "/" + to_string(dX);
        mp[str]++;
        curMaxi = max(curMaxi, mp[str]);
      }
      maxi = max(maxi, curMaxi + dup);
    }
    return maxi;
  }
};