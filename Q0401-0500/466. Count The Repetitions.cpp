class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int idx = 0;
    int count = 0;
    vector<int> vI(n1, 0);
    vector<int> vC(n1, 0);
    for (int i = 0; i < n1; ++i) {
      for (char c : s1) {
        if (c == s2[idx]) {
          idx++;
          if (idx == s2.size()) {
            idx = 0;
            count++;
          }
        }
      }
      for (int j = 0; j < i; ++j) {
        if (vI[j] == idx) {
          int rem = n1 - (j + 1);
          int rR = i - j;
          int Rc = count - vC[j];
          int tC = (rem / rR) * Rc + vC[j + rem % rR];
          return tC / n2;
        }
      }
      vI[i] = idx;
      vC[i] = count;
    }
    return count / n2;
  }
};