class Solution {
public:
  int countKConstraintSubstrings(string s, int k) {
    int n = s.length();
    int tSub = (n * (n + 1)) / 2;
    int exc = 0;
    int i = 0;
    int j = 0;

    for (int i = 0; i <= n - k; i++) {
      vector<int> v(2, 0);

      for (int j = i; j < n; j++) {
        v[s[j] - '0']++;

        if (v[0] > k && v[1] > k) {
          exc += n - j;
          break;
        }
      }
    }

    return tSub - exc;
  }
};