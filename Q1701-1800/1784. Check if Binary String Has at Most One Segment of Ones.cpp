class Solution {
public:
  bool checkOnesSegment(string s) {
    int cnt = count(s.begin(), s.end(), '0');
    if (cnt == 0) {
      return true;
    } else {
      string st = s;
      sort(st.rbegin(), st.rend());
      if (s == st) {
        return true;
      } else
        return false;
    }
  }
};