class Solution {
public:
   int maxValue(int n, int index, int maxSum) {
    int s = index, e = index;
    int ans = 1;
    maxSum -= n;
    while (s > 0 || e < n - 1) {
        int len = e - s + 1;
        if (maxSum >= len) {
            maxSum -= len;
            ans++;
            s = max(0, s - 1);
            e = min(n - 1, e + 1);
        } else {
            break;
        }
    }
    ans += maxSum / n;
    return ans;
}
};