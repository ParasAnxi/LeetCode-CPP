class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(int i : nums){
            if(k==0 || k == 1 || i != nums[k-2] ){
                nums[k++] = i;
            }
        }
        return k;
    }
};