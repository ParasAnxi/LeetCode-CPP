class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int a = 0;
        for (char c : s) {
            if (c == '0') {
                ++a;
            }
        }
        int ans = a;
        for (char c : s) {
            if (c == '0') {
                ans = min(ans, --a);
            } else {
                ++a;
            }
        }
        return ans;
    }
};