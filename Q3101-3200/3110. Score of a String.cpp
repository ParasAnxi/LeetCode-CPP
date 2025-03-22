class Solution {
public:
    int scoreOfString(string s) {
        long long ans = 0;
        for(int i = 1;i < s.length();i++){
            ans += abs((s[i] - 'a')-(s[i - 1] - 'a'));
        }
        return ans; 
    }
};