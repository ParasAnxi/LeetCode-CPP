class Solution {
public:
  void solve(int lvl, set<int> &st, int &ans) {
    if (lvl == 0) {
      ans++;
      return;
    }
    set<int> s = st;
    for (auto i : s) {
      if (i % lvl == 0 || lvl % i == 0) {
        st.erase(i);
        solve(lvl - 1, st, ans);
        st.insert(i);
      }
    }
    return;
  }
  int countArrangement(int n) {
    int ans = 0;
    set<int> st;
    for (int i = 1; i <= n; i++) {
      st.insert(i);
    }
    solve(n, st, ans);
    return ans;
  }
};