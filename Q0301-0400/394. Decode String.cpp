class Solution {
public:
  string solve(string &s, int &i) {
    string ans = "";
    string st = "";
    while (i < s.size()) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        ans += s[i];
        i++;
      } else if (s[i] >= '0' && s[i] <= '9') {
        st += s[i];
        i++;
      } else if (s[i] == '[') {
        i++;
        string temp = solve(s, i);
        int n = stoi(st);
        for (int j = 0; j < n; j++) {
          ans += temp;
        }
        st = "";
      } else if (s[i] == ']') {
        i++;
        break;
      }
    }

    return ans;
  }
  string decodeString(string s) {
    int i = 0;
    return solve(s, i);
  }
};