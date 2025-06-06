class Solution {
public:
  bool isBalanced(string num) {
    int even = 0;
    int odd = 0;
    for (int i = 0; i < num.length(); i++) {
      if (i & 2 != 0) {
        even = even + (num[i] - '0');
      } else {
        odd = odd + (num[i] - '0');
      }
    }

    return even == odd;
  }
};