class Solution {
public:
  int smallestNumber(int n) {
    uint8_t exp = 1;
    uint16_t ele = pow(2, exp) - 1;
    while (ele < n) {
      exp++;
      ele = pow(2, exp) - 1;
    }
    return ele;
  }
};