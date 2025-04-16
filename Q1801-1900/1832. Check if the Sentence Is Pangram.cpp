class Solution {
public:
  bool checkIfPangram(string sentence) {
    set<char> ans;
    for (int i = 0; i < sentence.length(); i++) {
      ans.insert(sentence[i]);
    }
    if (ans.size() == 26) {
      return true;
    }
    return false;
  }
};