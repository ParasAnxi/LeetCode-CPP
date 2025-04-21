using umii = unordered_map<int, int>;
using umci = unordered_map<char, int>;
using vi = vector<int>;
#define pb push_back
class Solution {
public:
  int findPermutationDifference(string s, string t) {
    umci mp;
    int i = 0;
    int ans = 0;
    for (auto ch : s) {
      mp[ch] = i++;
    }
    for (int i = 0; i < t.length(); i++) {
      ans = ans + abs(i - (mp[t[i]]));
    }
    return ans;
  }
};