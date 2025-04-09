class Solution {
public:
  bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
    int n = arr.size();
    int m = pieces.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < pieces.size(); i++) {
      mp[pieces[i][0]] = i;
    }

    int i = 0;
    int j = 0;
    vector<int> curr;
    while (i < n) {
      if (j == curr.size()) {
        curr = pieces[mp[arr[i]]];
        j = 0;
      }
      while (i < n && j < curr.size()) {
        if (arr[i] != curr[j]){
            return false;
        }
        i++;
        j++;
      }
    }
    return true;
  }
};