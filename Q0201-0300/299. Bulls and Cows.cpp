class Solution {
public:
  string getHint(string secret, string guess) {
    unordered_map<char, int> mp;
    for (auto i : secret) {
      mp[i]++;
    }
    int bulls = 0;
    int cows = 0;
    int n = secret.size();
    for (int i = 0; i < n; i++) {
      if (secret[i] == guess[i]) {
        bulls++;
        mp[secret[i]]--;
        if (mp[secret[i]] == 0) {
          mp.erase(secret[i]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (secret[i] != guess[i] && mp.find(guess[i]) != mp.end()) {
        cows++;
        mp[guess[i]]--;
        if (mp[guess[i]] == 0) {
          mp.erase(guess[i]);
        }
      }
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};