#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string reformatNumber(string number) {
    string dig = "";
    for (auto i : number) {
      if (isdigit(i)) {
        dig += i;
      }
    }

    string ans = "";
    int i = 0;
    int n = dig.length();

    while (n - i > 4) {
      ans += dig.substr(i, 3) + "-";
      i += 3;
    }

    if (n - i == 4) {
      ans += dig.substr(i, 2) + "-" + dig.substr(i + 2, 2);
    } else {
      ans += dig.substr(i);
    }

    return ans;
  }
};
