class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int len = n+1;
        int start= 0, sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum >= target){
                len=min(len,i-start+1);
                sum-=nums[start];
                start++;
            }
        }
        return len==n+1 ? 0 : len;
    }
};