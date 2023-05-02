class Solution {
public:
    int arraySign(vector<int>& nums) {
        int p=0,n=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                p++;
            else if(nums[i]<0)
                n++;
            else 
                return 0;
        }
        if(n%2==0)
            return 1;
        return -1;
    }
};