using mci = map<char,int>;
class Solution {
public:
  int maxDifference(string s) {
    mci mpp;
    for (int i = 0; i < s.length(); i++) {
      mpp[s[i]]++;
    }

    int maxi = INT_MIN;
    int mini = INT_MAX;

    for (auto &i : mpp) {
      if (i.second % 2 == 0) {
        mini = min(mini, i.second);
      } else {
        maxi = max(maxi, i.second);
      }
    }

    return maxi - mini;
  }
};