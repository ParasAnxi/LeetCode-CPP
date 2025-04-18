class Solution {
public:
  int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    int n = fruits.size();
    vector<int> visited(n, -1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (fruits[i] <= baskets[j] && visited[j] != 1) {
          visited[j] = 1;
          break;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (visited[i] == -1) ans++;
    }
    return ans;
  }
};