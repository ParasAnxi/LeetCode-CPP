class Solution {
public:
  bool canAliceWin(int n) {
    int ans = 0;
    int x = 10;
    while (n >= x) {
      n -= x--;
      ans++;
    }
    return ans % 2 == 1;
  }
};