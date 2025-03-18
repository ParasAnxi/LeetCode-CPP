class Solution{
public:
    int longestNiceSubarray(vector<int> &nums){
        int s = 0, e = 0, n = nums.size();
        int ans = 0, mask = 0;
        while (e < n){
            while ((mask & nums[e]) != 0){     
                mask ^= nums[s++];
            }
            mask |= nums[e];
            ans = max(ans, e - s + 1);
            e++;
        }
        return ans;
    }
};