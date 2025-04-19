class Solution {
public:
  string getEncryptedString(string s, int k) {
    int n = s.size();
    k = k % n;
    string ans = "";
    for (int i = 0; i < n - k; i++) ans += s[i + k];
    for (int i = 0; i < k; i++) ans += s[i];
    return ans;
  }
};