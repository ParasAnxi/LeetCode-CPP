class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0 , i = 0 , ans = 0;
        while(i < nums.size()){
            if(nums[i] == 0){
                i++;
                cnt2 = 0;
                while(i < nums.size() && nums[i] == 1){
                    i++;
                    cnt2++;
                }
                ans = max(ans, cnt1 + cnt2);
                cnt1 = cnt2;
            }
            else{
                cnt1++;
                i++;
            }
        }
        ans = max(ans, cnt1 - 1);
        return ans;
    }
};