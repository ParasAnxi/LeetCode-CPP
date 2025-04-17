class Solution {
public:
  bool wordPattern(string pattern, string s) {
    string wd = "";
    vector<string> v;
    for (char c : s) {
      if (c != ' ') {
        wd += c;
      } else {
        v.push_back(wd);
        wd = "";
      }
    }
    v.push_back(wd);

    if (pattern.size() != v.size())
      return false;

    unordered_map<char, string> charToWord;
    unordered_map<string, char> wordToChar;

    for (int i = 0; i < pattern.size(); ++i) {
      char c = pattern[i];
      string st = v[i];

      if (charToWord.count(c) && charToWord[c] != st)
        return false;
      if (wordToChar.count(st) && wordToChar[st] != c)
        return false;

      charToWord[c] = st;
      wordToChar[st] = c;
    }

    return true;
  }
};