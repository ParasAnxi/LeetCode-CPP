class Solution {
public:
  int strongPasswordChecker(string password) {
    int n = password.size();
    bool lc = 0, uc = 0, dig = 0;
    for (char c : password) {
      if (islower(c))
        lc = 1;
      if (isupper(c))
        uc = 1;
      if (isdigit(c))
        dig = 1;
    }
    int miss = !lc + !uc + !dig;
    int rep = 0, oneSeq = 0, twoSeq = 0;
    for (int i = 2; i < n;) {
      if (password[i] == password[i - 1] && password[i] == password[i - 2]) {
        int m = 2;
        while (i < n && password[i] == password[i - 1]) {
          m++;
          i++;
        }
        rep += m / 3;
        if (m % 3 == 0)
          oneSeq++;
        else if (m % 3 == 1)
          twoSeq++;
      } else {
        i++;
      }
    }
    if (n < 6) {
      return max(miss, 6 - n);
    }
    if (n <= 20) {
      return max(miss, rep);
    }
    int del = n - 20;
    int x = min(del, oneSeq);
    rep -= x;
    del -= x;
    x = min(del, twoSeq * 2);
    rep -= x / 2;
    del -= x;
    rep -= del / 3;
    return (n - 20) + max(miss, rep);
  }
};
