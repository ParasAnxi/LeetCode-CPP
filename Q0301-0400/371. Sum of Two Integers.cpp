class Solution {
public:
  int sum(int x, int y) {
    while (y != 0) {
      int carry = (x & y);
      x = (x ^ y);
      y = carry << 1;
    }
    return x;
  }
  int sub(int x, int y) {
    while (y != 0) {
      int carry = ((~x) & y);
      x = (x ^ y);
      y = (carry << 1);
    }
    return x;
  }
  int getSum(int a, int b) {
    if (a == 0) {
      return b;
    } else if (b == 0) {
      return a;
    } else if (a >= 0 && b >= 0) {
      return sum(a, b);
    } else if (a < 0 && b < 0) {
      return -1 * sum(-a, -b);
    } else if (a < 0 && b > 0) {
      return sub(b, -a);
    } else {
      return sub(a, -b);
    }
  }
};