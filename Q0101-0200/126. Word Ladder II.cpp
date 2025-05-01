class Solution {
public:
  void solve(vector<vector<string>> &ans,
             unordered_map<string, vector<string>> &adj, string wd,
             const string &beginWord, vector<string> &path) {
    if (wd == beginWord) {
      vector<string> vT = path;
      reverse(vT.begin(), vT.end());
      ans.push_back(vT);
      return;
    }

    for (auto &prev : adj[wd]) {
      path.push_back(prev);
      solve(ans, adj, prev, beginWord, path);
      path.pop_back();
    }
  }
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    vector<vector<string>> ans;

    if (st.find(endWord) == st.end())
      return ans;

    unordered_map<string, vector<string>> adj;
    unordered_set<string> currLvl{beginWord};
    bool found = false;

    while (!currLvl.empty() && !found) {
      unordered_set<string> nextLvl;
      for (auto wd : currLvl)
        st.erase(wd);

      for (const string &wd : currLvl) {
        string w = wd;
        for (int i = 0; i < w.size(); ++i) {
          char oG = w[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            w[i] = c;
            if (st.count(w)) {
              nextLvl.insert(w);
              adj[w].push_back(wd);
              if (w == endWord)
                found = true;
            }
          }
          w[i] = oG;
        }
      }
      currLvl = nextLvl;
    }

    if (!found)
      return ans;

    vector<string> path{endWord};
    solve(ans, adj, endWord, beginWord, path);
    return ans;
  }
};