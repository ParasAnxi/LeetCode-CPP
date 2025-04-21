class Solution {
public:
  int possibleStringCount(string word) {
    int ans = 1;
    int prev = -1;
    int count = 1;

    for (int i = 0; i < word.size(); i++) {
      if (word[i] != prev) {
        ans += (count - 1);
        prev = word[i];
        count = 1;
      } else {
        count++;
      }
      if (i == word.size() - 1) {
        ans += (count - 1);
      }
    }

    return ans;
  }
};