class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n = nums.size();        
        vector<int> lis;        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int idx = upper_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            ans.push_back(idx + 1);
            if(idx == lis.size())
                lis.push_back(nums[i]);
            else{
                lis[idx] = nums[i];
            }
        }
        return ans;
    }
};