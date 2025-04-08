class Solution {
public:
  int countSegments(string s) {
    int count = 0;
    bool visited = false;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ' ' && !visited) {
        count++;
        visited = true;
      } else if (s[i] == ' ') {
        visited = false;
      }
    }

    return count;
  }
};