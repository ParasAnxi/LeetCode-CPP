class Solution{
    bool comp(unordered_map<char, int> &mp){
        return mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0;
    }

public:
    int numberOfSubstrings(string s){
        int n = s.length();
        unordered_map<char, int> mp;
        mp['a'] = 0, mp['b'] = 0, mp['c'] = 0;
        int ans = 0;
        int i = 0;
        for (int j = 0; j < n; j++){
            mp[s[j]]++;
            if (comp(mp)){
                ans += (n - j);
                mp[s[i]]--;
                i++;
            }
            while (i < j && comp(mp)){
                ans += (n - j);
                mp[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};