class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> nc, mg;
    for (char i : ransomNote)
      nc[i]++;
    for (char i : magazine)
      mg[i]++;

    for (auto &i : nc)
      if (mg[i.first] < i.second)
        return 0;

    return 1;
  }
};