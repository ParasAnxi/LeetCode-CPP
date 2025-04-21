using vi = vector<int>;
#define pb push_back
class Solution {
public:
  int numberOfSpecialChars(string word) {
    int n = word.size();
    vi v1(26, 0);
    vi v2(26, 0);
    for (int i = 0; i < n; i++) {
      if (word[i] >= 'A' && word[i] <= 'Z') { 
        v1[word[i] - 'A']++;
      } else if (word[i] >= 'a' && word[i] <= 'z') {
        v2[word[i] - 'a']++;
      }
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
      if (v1[i] && v2[i]) {
        count++;
      }
    }
    return count;
  }
};