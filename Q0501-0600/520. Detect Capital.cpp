class Solution {
public:
  bool detectCapitalUse(string word) {
    int n = word.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (isupper(word[i])) {
        count++;
      }
    }
    if (count == 1) {
      return (isupper(word[0]) ? 1 : 0);
    }
    return (count == n || count == 0);
  }
};