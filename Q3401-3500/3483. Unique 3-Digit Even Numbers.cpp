class Solution {
public:
  void solve(int index, vector<int> digits, int n, set<int> &s) {
    if (index >= n) {
      return;
    }

    if (digits[index] % 2 == 1) {
      solve(index + 1, digits, n, s);
      return;
    }

    int x = digits[index];

    for (int i = 0; i < n; i++) {
      if (i != index && digits[i] != 0) {
        for (int j = 0; j < n; j++) {
          if (j != index && j != i) {
            s.insert(digits[i] * 100 + digits[j] * 10 + x);
          }
        }
      }
    }

    solve(index + 1, digits, n, s);
  }

  int totalNumbers(vector<int> &digits) {
    set<int> s;
    solve(0, digits, digits.size(), s);
    return s.size();
  }
};