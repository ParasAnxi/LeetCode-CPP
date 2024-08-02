class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            if(nums[i] == 1) count++;
        }
        if(count == n || count == n-1) return 0;
        for(int i = 0; i < count-1; i++){
            nums.push_back(nums[i]);
        }
        int ones = 0;
        int start = 0;
        int ans = INT_MAX;
        for(int end = 0; end < nums.size() ; end++){
            if(nums[end] == 1) ones++;
            if(end-start == count-1){
                ans = min(ans,count-ones);
                ones -= nums[start];
                start++;
            }
        }
        return ans == INT_MAX?0:ans;
    }
};