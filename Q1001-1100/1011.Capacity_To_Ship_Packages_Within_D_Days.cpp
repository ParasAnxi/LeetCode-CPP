class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin(), weights.end(), 0);
        while (s < e) {
            int mid = s + (e - s) / 2;
            int cur = 0, need = 1;
            for (int w : weights) {
                if (cur + w > mid) {
                    cur = 0;
                    need++;
                }
                cur += w;
            }
            if (need <= days) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};