class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int Mod = 0, ans = 0;

        vector<int> Groups(k);
        Groups[0] = 1;

        for (int num : nums) {
            Mod = (Mod + num % k + k) % k;
            ans += Groups[Mod];
            Groups[Mod]++;
        }
        return ans;
    }
};