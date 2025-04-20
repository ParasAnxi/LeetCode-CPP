using mii = map<int,int>;
class Solution {
public:
  string findValidPair(string s) {
    mii mpp;
    for (int i = 0; i < s.size(); i++) {
      mpp[s[i]]++;
    }
    string ans = "";
    for (int i = 0; i < s.size() - 1; i++) {
      char curr = s[i];
      char next = s[i + 1];
      if (curr != next && (mpp[curr] == (curr - '0')) &&
          mpp[next] == (next - '0')) {
        ans += curr;
        ans += next;
        return ans;
      }
    }
    return "";
  }
};