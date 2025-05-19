class Solution {
public:
  int maxProduct(vector<string> &words) {
    int n = words.size();
    int maxi = 0;
    vector<unordered_set<char>> st(n);
    for (int i = 0; i < n; i++) {
      for (char c : words[i]) {
        st[i].insert(c);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        bool flg = false;
        for (char c : st[i]) {
          if (st[j].find(c) != st[j].end()) {
            flg = true;
            break;
          }
        }
        if (!flg) {
          maxi = max(maxi, (int)words[i].size() * (int)words[j].size());
        }
      }
    }
    return maxi;
  }
};