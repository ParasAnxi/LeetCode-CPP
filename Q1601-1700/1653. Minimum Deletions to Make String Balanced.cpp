class Solution {
public:
    int minimumDeletions(string s) {
        int count = 0;
        int ans = 0;
        for (char ch : s) {
            if (ch == 'b') {
                ++count;
            } else if (ch == 'a') {
                ans = min(ans + 1, count);
            }
        }

        return ans;
    }
};