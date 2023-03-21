class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        long long x=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                x++;
            }
            else{
                ans+=((x+1)*x)/2;
                x=0;
            }
        }
        ans+=((x+1)*x)/2;
        x=0;
        return ans;
    }
};