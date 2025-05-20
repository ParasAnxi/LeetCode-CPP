class Solution {
public:
  bool isSelfCrossing(vector<int> &distance) {
    int n = distance.size();
    for (int i = 3; i < n; ++i) {
      if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3])
        return 1;
      if (i >= 4) {
        if (distance[i - 1] == distance[i - 3] &&
            distance[i] + distance[i - 4] >= distance[i - 2])
          return 1;
      }
      if (i >= 5) {
        bool op1 = distance[i - 2] >= distance[i - 4] &&
                   distance[i] + distance[i - 4] >= distance[i - 2];
        bool op2 = distance[i - 1] <= distance[i - 3] &&
                   distance[i - 1] + distance[i - 5] >= distance[i - 3];
        if (op1 && op2)
          return 1;
      }
    }
    return 0;
  }
};