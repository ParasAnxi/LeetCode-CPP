class Solution {
public:
  bool isPal(string &s) {
    int st = 0, e = s.size() - 1;
    while (st < e) {
      if (s[st++] != s[e--])
        return 0;
    }
    return 1;
  }
  vector<vector<int>> palindromePairs(vector<string> &words) {
    int n = words.size();
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
      string rev = words[i];
      reverse(rev.begin(), rev.end());
      mp[rev] = i;
    }
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      string st = words[i];
      for (int j = 0; j <= st.size(); j++) {
        string pF = st.substr(0, j);
        string sF = st.substr(j);
        if (isPal(sF) && mp.count(pF) && mp[pF] != i) {
          ans.push_back({i, mp[pF]});
        }
        if (j != 0 && isPal(pF) && mp.count(sF) && mp[sF] != i) {
          ans.push_back({mp[sF], i});
        }
      }
    }
    return ans;
  }
};