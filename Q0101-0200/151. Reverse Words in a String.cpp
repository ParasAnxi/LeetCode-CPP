class Solution {
public:
  string reverseWords(string s) {
    int e = s.length() - 1;
    string st = "";
    string ans = "";

    while (e >= 0) {

      if (s[e] != ' ') {
        st += s[e];
      } else {
        if (!st.empty()) {
          reverse(st.begin(), st.end());
          if (!ans.empty())
            ans.push_back(' ');
          ans += st;
          st = "";
        }
      }
      e--;
    }
    if (!st.empty()) {
      reverse(st.begin(), st.end());
      if (!ans.empty())
        ans.push_back(' ');
      ans += st;
    }

    return ans;
  }
};