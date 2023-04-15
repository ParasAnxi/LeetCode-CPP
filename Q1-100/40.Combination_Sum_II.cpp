class Solution {
public:
    void solve(int i, int t, vector<int> &v, vector<int> &temp, set<vector<int>> &ans){
      if(t == 0){
        ans.insert(temp);
        return;
      }
      for(int idx = i; idx < v.size(); idx++){
        if(idx > i and v[idx] == v[idx - 1]) continue;
        if(t - v[idx] < 0) break;
        temp.emplace_back(v[idx]);
        solve(idx + 1, t - v[idx], v, temp, ans);
        temp.pop_back();
      }
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
      set<vector<int>> ans;
      vector<int> temp;
      sort(v.begin(), v.end());
      solve(0, t, v, temp, ans);
      vector<vector<int>> res(ans.begin(), ans.end());
      return res;
    }
};