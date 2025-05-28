class Solution {
public:
  int findMinMoves(vector<int> &machines) {
    int n = machines.size();
    int sum = accumulate(machines.begin(), machines.end(), 0);
    if (sum % n != 0)
      return -1;
    int tar = sum / n;
    int mini = -1;
    int lN = 0;
    int x = 0;
    for (auto i : machines) {
      mini = max(mini, i - tar);
      mini = max(abs(lN - x), mini);
      lN += tar;
      x += i;
    }
    return mini;
  }
};