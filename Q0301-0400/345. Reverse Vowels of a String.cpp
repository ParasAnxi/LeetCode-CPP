class Solution {
public:
  string reverseVowels(string s) {
    int st = 0;
    int e = s.size() - 1;
    string vow = "aeiouAEIOU";

    while (st < e) {
      while (st < e && vow.find(s[st]) == string::npos)
        st++;
      while (st < e && vow.find(s[e]) == string::npos)
        e--;

      swap(s[st], s[e]);
      st++;
      e--;
    }
    return s;
  }
};