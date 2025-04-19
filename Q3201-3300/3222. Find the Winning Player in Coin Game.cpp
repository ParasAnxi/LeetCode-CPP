class Solution {
public:
  string winningPlayer(int x, int y) {
    int ans = 0;
    while (x >= 1 && y >= 4) {
      ans ^= 1;
      x--;
      y -= 4;
    }
    return ans ? "Alice" : "Bob";
  }
};