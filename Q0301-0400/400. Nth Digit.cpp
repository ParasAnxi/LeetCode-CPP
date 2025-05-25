class Solution {
public:
  int findNthDigit(int n) {
    long long dig = 1;
    long long count = 9;
    long long s = 1;

    while (n > dig * count) {
      n -= dig * count;
      dig++;
      count *= 10;
      s *= 10;
    }

    s += (n - 1) / dig;

    string val = to_string(s);
    return val[(n - 1) % dig] - '0';
  }
};