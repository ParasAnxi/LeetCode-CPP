class Solution {
public:
  void solve(const string &s, int sL, int st, int mini, string path,
             unordered_map<char, int> &mp, int bnc, vector<string> &ans) {
    if (path.size() == sL && bnc == 0) {
      ans.push_back(path);
      return;
    }
    for (int i = st; i < s.size(); i++) {
      char c = s[i];
      if (i > st && s[i] == s[i - 1])
        continue;
      if (c == '(' && mp[c] > mini)
        continue;
      if (c == ')' && (mp[c] > mp['('] || bnc == 0))
        continue;
      if (c == '(')
        bnc++;
      if (c == ')')
        bnc--;
      mp[c]++;
      solve(s, sL, i + 1, mini, path + c, mp, bnc, ans);
      mp[c]--;
      if (c == '(')
        bnc--;
      if (c == ')')
        bnc++;
    }
  }
  vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    unordered_map<char, int> mp;
    int lN = 0;
    for (char ch : s) {
      if (ch == '(')
        mp['(']++;
      if (ch == ')' && mp[')'] < mp['('])
        mp[')']++;
      if (ch != '(' && ch != ')')
        lN++;
    }
    int miniC = mp['('] > mp[')'] ? mp[')'] : mp['('];
    int sL = lN + 2 * miniC;
    mp['('] = 0;
    mp[')'] = 0;
    solve(s, sL, 0, miniC, "", mp, 0, ans);
    if (ans.empty()) {
      string str = "";
      for (char ch : s)
        if (ch != '(' && ch != ')')
          str += ch;
      ans.push_back(str);
    }
    return ans;
  }
};