class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr= nums;
        sort(arr.begin(), arr.end());
        
        int len= nums.size(),i=0,j=len-1;
        
        while(i<len){
            if(arr[i]!= nums[i])
                break;
            i++;
        }
        
        while(j>=0){
            if(arr[j]!= nums[j])
                break;
            j--;
        }
        
        return (i>=j)? 0: j-i+1;
    }
};