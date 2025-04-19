class Solution {
public:
  bool canAliceWin(vector<int> &nums) {
    int x = 0;
    int y = 0;
    for (auto i : nums) {
      if (i <= 9)
        x += i;
      else
        y += i;
    }
    return x != y;
  }
};