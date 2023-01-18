class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int n = nums.size();
        vector<int> rm(n);
        rm[n - 1] = nums[n - 1];
        for (int ss = nums[n - 1], i = n - 2; i >= 0; --i) {
            ss += nums[i];
            rm[i] = max(rm[i + 1], ss);
        }
        int ms = nums[0];
        int sps = nums[0];
        for (int i = 0, ss = 0, cm = 0; i < n; ++i) {
            cm = max(cm, 0) + nums[i];
            ms = max(ms, cm);
            ss += nums[i];
            if (i + 1 < n) {
                sps = max(sps, ss + rm[i + 1]);
            }
        }
        return max(ms, sps);
    }
};