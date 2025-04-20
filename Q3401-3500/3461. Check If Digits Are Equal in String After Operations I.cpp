class Solution {
public:
  bool hasSameDigits(string s) {
    int n = s.size();
    string ans = "";
    if (n < 2) {
      return false;
    }
    while (n > 2) {
      for (int i = 0; i < n - 1; i++) {
        int sum = (s[i] - '0') + (s[i + 1] - '0');
        s[i] = (sum % 10) + '0';
      }
      s.pop_back();
      n--;
    }

    return s[0] == s[1];
  }
};