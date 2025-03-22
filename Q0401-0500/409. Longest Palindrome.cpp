class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (char c: s) 
          mp[c]++;
        int count = 0;
        int odd = 0;
        for (pair<char, int> p: mp) {
            count += p.second / 2;
            if (p.second & 1) odd = 1;
        }
        count = count * 2 + odd;
        return count;
    }
};