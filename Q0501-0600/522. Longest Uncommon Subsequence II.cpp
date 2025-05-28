class Solution {
public:
  string findLongestWord(string s, vector<string> &dictionary) {
    int n = s.size();
    vector<vector<int>> v(n, vector<int>(26, -1));

    vector<int> curr(26, -1);

    for (int i = n - 1; i >= 0; --i) {
      v[i] = curr;
      curr[s[i] - 'a'] = i;
    }

    string ans = "";
    for (auto &i : dictionary) {
      int index = curr[i[0] - 'a'];
      for (int j = 1; index != -1 && j < i.size(); ++j)
        index = v[index][i[j] - 'a'];

      if (index == -1)
        continue;

      if (i.size() > ans.size() || (i.size() == ans.size() && i < ans))
        ans = i;
    }

    return ans;
  }
};