class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) { 
        vector<int> ans(nums.size(),-1);
        int win=0;
         win=k*2+1;
        int j=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(i-j+1<win) sum+=nums[i];
            else if(i-j+1==win){
                sum+=nums[i];
                int div=sum/win;
                ans[i-k]=div;
            }
            else if(i-j+1>win){
                sum-=nums[j];
                j++;
                i--;
            }
        }
        return ans;
    }
};