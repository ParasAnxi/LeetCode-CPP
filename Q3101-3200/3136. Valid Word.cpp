class Solution {
public:
  bool isValid(string word) {
    int n = word.length() >= 3;
    int valid = 1;
    int vow = 0;
    int cons = 0;

    for (int i = 0; i < word.length(); i++) {
      char ch = word[i];
      int isDig = ch >= 48 && ch <= 57;
      int isUc = ch >= 65 && ch <= 90;
      int isLc = ch >= 97 && ch <= 122;
      if (!(isDig || isUc || isLc))
        return 0;

      if (!isDig) {
        if (!vow || !cons) {
          if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
              ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vow = 1;
          } else {
            cons = 1;
          }
        }
      }
    }

    return n && valid && vow && cons;
  }
};