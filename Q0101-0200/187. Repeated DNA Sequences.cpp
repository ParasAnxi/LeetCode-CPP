class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    unordered_map<string, int> mp;
    int n = 10;
    for (int i = 0; i + n <= s.length(); i++) {
      auto x = s.substr(i, n);
      if (mp[x] == 1) {
        ans.push_back(x);
      }
      mp[x]++;
    }
    return ans;
  }
};