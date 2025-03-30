class Solution {
public:
  vector<int> partitionLabels(string s) {
    unordered_map<char, int> mp;
    vector<int> ans;
    int prev = -1;
    for (int i = 0; i < s.length(); i++) {
      mp[s[i]] = i;
    }
    int pos = 0;
    for (int i = 0; i < s.length(); i++) {
      pos = max(pos, mp[s[i]]);

      if (i == pos) {
        ans.push_back(pos - prev);
        prev = pos;
      }
    }
    return ans;
  }
};