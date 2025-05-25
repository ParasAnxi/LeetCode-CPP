class Solution {
public:
  int longestSubstring(string s, int k) {
    int n = s.length();
    int ans = 0;
    for (int i = 1; i <= 26; i++) {
      int unq = 0;
      int st = 0, e = 0;
      int count = 0;
      unordered_map<char, int> mp;
      while (e < n) {
        if (mp[s[e]] == 0)
          unq++;
        mp[s[e]]++;
        if (mp[s[e]] == k)
          count++;
        while (unq > i) {
          if (mp[s[st]] == k)
            count--;
          mp[s[st]]--;
          if (mp[s[st]] == 0)
            unq--;
          st++;
        }
        if (unq == count) {
          ans = max(ans, e - st + 1);
        }
        e++;
      }
    }
    return ans;
  }
};