#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
      return "0";

    long long n = numerator;
    long long d = denominator;

    int sign = (n > 0) ^ (d > 0) ? -1 : 1;
    n = abs(n);
    d = abs(d);

    long long integerPart = n / d;
    long long remainder = n % d;

    string ans = to_string(integerPart);
    if (remainder == 0) {
      return sign == -1 ? "-" + ans : ans;
    }

    ans += ".";
    unordered_map<long long, int> mp;
    string fraction = "";

    int pos = 0;
    while (remainder != 0) {
      if (mp.count(remainder)) {
        fraction.insert(mp[remainder], "(");
        fraction += ")";
        break;
      }
      mp[remainder] = pos++;
      remainder *= 10;
      fraction += to_string(remainder / d);
      remainder %= d;
    }

    if (sign == -1) {
      ans = "-" + ans;
    }

    return ans + fraction;
  }
};
