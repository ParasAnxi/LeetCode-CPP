class Solution {
public:
  string convertToBase7(int num) {
    if (num == 0)
      return "0";

    bool neg = num < 0 ? 1 : 0;
    num = abs(num);
    string ans = "";

    while (num > 0) {
      ans += (num % 7) + '0';
      num /= 7;
    }

    if (neg)
      ans += '-';

    reverse(ans.begin(), ans.end());
    return ans;
  }
};